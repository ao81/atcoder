#!/usr/bin/env python3
"""atc — AtCoder ローカルテスト支援ツール (標準ライブラリのみ)

サンプルケースの自動取得・照合、コンテストディレクトリの作成、
ストレステストなどをまとめた CLI。提出以外を全部やる。

使い方: atc help
"""

import html
import json
import os
import re
import subprocess
import sys
import time
import urllib.error
import urllib.request

BASE_URL = "https://atcoder.jp"
BASE_DIR = os.path.expanduser(os.environ.get("ATC_BASE", "~/atcoder"))
SESSION_FILE = os.path.expanduser("~/.config/atc/session")
DEFAULT_TL = float(os.environ.get("ATC_TL", "2.0"))   # 実行時間制限 (秒)
EPS = float(os.environ.get("ATC_EPS", "1e-6"))        # 浮動小数点の許容誤差
CONTEST_KINDS = ("abc", "arc", "agc", "ahc")

# ---------- 色 ----------
def _c(code, s):
    if not sys.stdout.isatty() and os.environ.get("ATC_COLOR") != "1":
        return s
    return f"\033[{code}m{s}\033[0m"

def green(s):  return _c("1;32", s)
def red(s):    return _c("1;31", s)
def yellow(s): return _c("1;33", s)
def magenta(s):return _c("1;35", s)
def cyan(s):   return _c("36", s)
def bold(s):   return _c("1", s)
def dim(s):    return _c("2", s)


def die(msg):
    print(red("エラー: ") + msg, file=sys.stderr)
    sys.exit(1)


# ---------- HTTP ----------
_last_request = 0.0

def http_get(url, _retry=True):
    global _last_request
    wait = _last_request + 1.0 - time.monotonic()  # 連続アクセスを 1 秒間隔に抑える
    if wait > 0:
        time.sleep(wait)
    headers = {"User-Agent": "Mozilla/5.0 (compatible; atc-local-tester)"}
    sess = read_session()
    if sess:
        headers["Cookie"] = "REVEL_SESSION=" + sess
    req = urllib.request.Request(url, headers=headers)
    try:
        with urllib.request.urlopen(req, timeout=15) as r:
            _last_request = time.monotonic()
            return r.read().decode("utf-8", "replace")
    except urllib.error.HTTPError as e:
        _last_request = time.monotonic()
        if e.code == 429 and _retry:
            time.sleep(4)
            return http_get(url, _retry=False)
        raise


def read_session():
    try:
        with open(SESSION_FILE) as f:
            return f.read().strip() or None
    except OSError:
        return None


# ---------- 問題の特定 ----------
def infer_contest(path):
    """パスからコンテスト名 (例 abc466) を推定する。"""
    p = path.replace("\\", "/")
    m = re.search(r"/(%s)/\d+/(\d+)(?:/|$)" % "|".join(CONTEST_KINDS), p)
    if m:
        return m.group(1) + m.group(2).zfill(3)
    m = re.search(r"/((?:%s)\d{3,4})(?:/|$)" % "|".join(CONTEST_KINDS), p)
    if m:
        return m.group(1)
    return None


def contest_dir(contest):
    """abc466 -> ~/atcoder/abc/46/466"""
    m = re.fullmatch(r"(%s)(\d{3,4})" % "|".join(CONTEST_KINDS), contest)
    if not m:
        die(f"コンテスト名の形式が不正です: {contest} (例: abc467)")
    kind, num = m.groups()
    return os.path.join(BASE_DIR, kind, num[:-1], num)


def pick_source(arg):
    """引数のソースファイル、無ければカレントで最後に編集した .cpp を返す。"""
    if arg:
        src = arg if arg.endswith(".cpp") else arg + ".cpp"
        if not os.path.exists(src):
            die(f"ソースファイルが見つかりません: {src}")
        return src
    cpps = [f for f in os.listdir(".") if f.endswith(".cpp")]
    if not cpps:
        die("カレントディレクトリに .cpp がありません")
    return max(cpps, key=lambda f: os.path.getmtime(f))


def problem_letter(src):
    stem = os.path.splitext(os.path.basename(src))[0].lower()
    return stem


# ---------- サンプル取得 ----------
def fetch_task_slugs(contest):
    """コンテストの問題一覧から {文字: スラッグ} を作る。"""
    url = f"{BASE_URL}/contests/{contest}/tasks?lang=ja"
    try:
        page = http_get(url)
    except urllib.error.HTTPError as e:
        if e.code == 404:
            die(f"コンテスト {contest} が見つかりません (未公開の可能性)")
        raise
    pairs = re.findall(
        r"href=[\"']/contests/%s/tasks/([\w\-]+)[\"'][^>]*>([^<]+)</a>" % re.escape(contest),
        page,
    )
    slugs = {}
    for slug, text in pairs:
        t = text.strip()
        if re.fullmatch(r"[A-Za-z][A-Za-z0-9]?", t) and t.lower() not in slugs:
            slugs[t.lower()] = slug
    if not slugs:
        hint = ""
        if "ログイン" in page or "login" in page.lower():
            hint = " (開催中のコンテストは `atc login` でセッション設定が必要です)"
        die(f"問題一覧を取得できませんでした: {url}{hint}")
    return slugs


def strip_tags(s):
    return re.sub(r"<[^>]*>", "", s)


def fetch_samples(contest, slug):
    """問題ページからサンプル [(in, out), ...] を取得する。"""
    url = f"{BASE_URL}/contests/{contest}/tasks/{slug}?lang=ja"
    page = http_get(url)
    sections = re.findall(
        r"<h3[^>]*>(.*?)</h3>\s*(?:<(?:div|section)[^>]*>\s*)*<pre[^>]*>(.*?)</pre>",
        page, re.DOTALL,
    )
    ins, outs = {}, {}
    for heading, body in sections:
        h = strip_tags(heading)
        m = re.search(r"(入力例|出力例|Sample Input|Sample Output)\s*(\d*)", h)
        if not m:
            continue
        kind = m.group(1)
        num = int(m.group(2) or "1")
        text = html.unescape(body).replace("\r\n", "\n").lstrip("\n")
        if kind in ("入力例", "Sample Input"):
            ins.setdefault(num, text)
        else:
            outs.setdefault(num, text)
    samples = [(ins[n], outs[n]) for n in sorted(ins) if n in outs]
    if not samples:
        # インタラクティブ問題: 入力例/出力例が無く「入出力例」の対話表になっている
        if ("インタラクティブ" in page or "入出力例" in page
                or "Sample Interaction" in page):
            return None, url
        hint = ""
        if "ログイン" in page and "入力例" not in page:
            hint = " (開催中のコンテストは `atc login` でセッション設定が必要です)"
        raise RuntimeError(f"サンプルが見つかりませんでした: {url}{hint}")
    return samples, url


def tests_dir(letter):
    return os.path.join("tests", letter)


def slug_cache_path():
    return os.path.join("tests", ".slugs.json")


def get_slug(contest, letter):
    cache = {}
    try:
        with open(slug_cache_path()) as f:
            cache = json.load(f)
    except (OSError, ValueError):
        pass
    if letter not in cache:
        slugs = fetch_task_slugs(contest)
        # h と ex の相互フォールバック (旧 ABC の Ex 問題)
        if letter == "h" and "h" not in slugs and "ex" in slugs:
            slugs["h"] = slugs["ex"]
        cache.update(slugs)
        os.makedirs("tests", exist_ok=True)
        with open(slug_cache_path(), "w") as f:
            json.dump(cache, f, ensure_ascii=False, indent=1)
    if letter not in cache:
        die(f"問題 {letter.upper()} が {contest} に見つかりません")
    return cache[letter]


def ensure_samples(contest, letter, refetch=False):
    """サンプルを tests/<letter>/ に保存し、(ケース一覧, インタラクティブ?) を返す。"""
    tdir = tests_dir(letter)
    marker = os.path.join(tdir, ".interactive")
    have = sorted(f for f in os.listdir(tdir)) if os.path.isdir(tdir) else []
    interactive = os.path.exists(marker)
    if refetch or (not interactive and not any(f.endswith(".in") for f in have)):
        slug = get_slug(contest, letter)
        print(dim(f"サンプル取得中: {contest}/{slug} ..."), flush=True)
        samples, url = fetch_samples(contest, slug)
        os.makedirs(tdir, exist_ok=True)
        with open(os.path.join(tdir, ".url"), "w") as f:
            f.write(url.split("?")[0])
        interactive = samples is None
        if interactive:
            with open(marker, "w") as f:
                f.write("この問題はインタラクティブ形式 (サンプル照合不可)\n")
            print(yellow("  -> インタラクティブ問題 (通常サンプルなし)"))
        else:
            if os.path.exists(marker):
                os.remove(marker)
            for i, (si, so) in enumerate(samples, 1):
                with open(os.path.join(tdir, f"{i}.in"), "w") as f:
                    f.write(si)
                with open(os.path.join(tdir, f"{i}.out"), "w") as f:
                    f.write(so)
            print(dim(f"  -> {len(samples)} ケース保存 ({tdir}/)"))
    cases = []
    for f in sorted(os.listdir(tdir), key=natural_key):
        if f.endswith(".in"):
            base = f[:-3]
            out = os.path.join(tdir, base + ".out")
            cases.append((base, os.path.join(tdir, f), out if os.path.exists(out) else None))
    return cases, interactive


def natural_key(s):
    return [int(t) if t.isdigit() else t for t in re.split(r"(\d+)", s)]


def problem_url(letter):
    try:
        with open(os.path.join(tests_dir(letter), ".url")) as f:
            return f.read().strip()
    except OSError:
        return None


# ---------- コンパイル ----------
def compile_cpp(src, debug=False, quiet=False):
    """コンパイルして実行ファイルのパスを返す。最新ならスキップ。"""
    stem = os.path.splitext(os.path.basename(src))[0]
    bindir = os.path.join("tests", ".bin")
    binary = os.path.join(bindir, stem + (".dbg" if debug else ""))
    if (os.path.exists(binary)
            and os.path.getmtime(binary) > os.path.getmtime(src)
            and os.path.getmtime(binary) > os.path.getmtime(__file__)):
        return binary
    os.makedirs(bindir, exist_ok=True)
    with open(src, encoding="utf-8", errors="replace") as f:
        code = f.read()
    flags = ["-std=gnu++20", "-O2", "-Wall", "-Wextra"]
    link = []
    if "atcoder/" in code:
        for acl in (os.environ.get("ATC_ACL"),
                    os.path.join(BASE_DIR, "ac-library"),
                    os.path.join(BASE_DIR, "_ac-library")):
            if acl and os.path.isdir(acl):
                flags.append(f"-I{acl}")
                break
    if "gmpxx.h" in code:
        link += ["-lgmpxx", "-lgmp"]
    if debug:
        flags += ["-fsanitize=address", "-fsanitize=undefined", "-g", "-O0"]
        flags.remove("-O2")
    if not quiet:
        print(dim(f"コンパイル中: g++ {' '.join(flags)} {src}"), flush=True)
    r = subprocess.run(["g++", *flags, src, *link, "-o", binary])
    if r.returncode != 0:
        die(f"コンパイル失敗: {src}")
    return binary


# ---------- 照合 ----------
def normalize(s):
    return [line.rstrip() for line in s.rstrip("\n").split("\n")]


def outputs_match(expected, actual):
    """(一致?, 浮動小数点比較を使ったか)"""
    e, a = normalize(expected), normalize(actual)
    if e == a:
        return True, False
    et = expected.split()
    at = actual.split()
    if len(et) != len(at):
        return False, False
    used_float = False
    for x, y in zip(et, at):
        if x == y:
            continue
        try:
            fx, fy = float(x), float(y)
        except ValueError:
            return False, False
        if abs(fx - fy) > EPS * max(1.0, abs(fx), abs(fy)):
            return False, False
        used_float = True
    return True, used_float


def run_case(binary, in_path, tl):
    with open(in_path, "rb") as f:
        data = f.read()
    t0 = time.perf_counter()
    try:
        r = subprocess.run([binary], input=data, capture_output=True, timeout=tl)
    except subprocess.TimeoutExpired:
        return "TLE", "", "", tl
    ms = time.perf_counter() - t0
    out = r.stdout.decode("utf-8", "replace")
    err = r.stderr.decode("utf-8", "replace")
    if r.returncode != 0:
        return "RE", out, err + f"\n(exit code {r.returncode})", ms
    return "OK", out, err, ms


def show_block(title, text, limit=30):
    lines = text.rstrip("\n").split("\n")
    print(f"    {dim(title)}")
    for line in lines[:limit]:
        print(f"      {line}")
    if len(lines) > limit:
        print(dim(f"      ... (他 {len(lines) - limit} 行)"))


# ---------- コマンド ----------
def cmd_test(args):
    debug = "--debug" in args or "-d" in args
    refetch = "--refetch" in args or "-r" in args
    rest = [a for a in args if not a.startswith("-")]
    src = pick_source(rest[0] if rest else None)
    contest = infer_contest(os.path.join(os.getcwd(), src))
    if not contest:
        die("パスからコンテストを推定できません (例: ~/atcoder/abc/46/466/ で実行)")
    letter = problem_letter(src)

    cases, interactive = ensure_samples(contest, letter, refetch=refetch)
    binary = compile_cpp(src, debug=debug)
    url = problem_url(letter)

    print(f"\n{bold(contest.upper() + ' ' + letter.upper())} — {src}"
          + (f"  {cyan(url)}" if url else ""))
    print(dim("─" * 60))

    if interactive and not cases:
        print(yellow("  インタラクティブ問題のためサンプル照合はできません。"))
        print(f"  コンパイルは {green('OK')} です。動作確認は手動対話で:")
        print(f"    {cyan('atc run ' + src)}")
        print("  (入出力例は問題ページ参照。tests/%s/ に自作の .in/.out を置けば照合もできます)" % letter)
        print(dim("─" * 60))
        return 0

    n_ac = n_total = 0
    judged_all = True
    for name, in_path, out_path in cases:
        status, out, err, sec = run_case(binary, in_path, DEFAULT_TL)
        ms = f"{int(sec * 1000):>4} ms"
        label = f"  {name:>6}  "
        if status == "TLE":
            print(label + yellow("TLE") + f"  ({DEFAULT_TL:.0f} s 超過)")
            judged_all = False
        elif status == "RE":
            print(label + magenta("RE ") + f"  {ms}")
            show_block("stderr:", err.strip()[-2000:])
            judged_all = False
        elif out_path is None:
            n_total -= 1  # 期待値なし: 判定対象外
            print(label + cyan("---") + f"  {ms}  (期待出力なし)")
            show_block("output:", out)
        else:
            with open(out_path, encoding="utf-8", errors="replace") as f:
                expected = f.read()
            ok, used_float = outputs_match(expected, out)
            if ok:
                mark = green("AC ") + (dim(" (誤差許容)") if used_float else "")
                print(label + mark + f"  {ms}")
                n_ac += 1
            else:
                print(label + red("WA ") + f"  {ms}")
                with open(in_path, encoding="utf-8", errors="replace") as f:
                    show_block("入力:", f.read())
                show_block("期待:", expected)
                show_block("出力:", out)
                if err.strip():
                    show_block("stderr:", err.strip()[-1000:])
                judged_all = False
        n_total += 1

    print(dim("─" * 60))
    if n_total == 0 and judged_all:
        print(yellow("判定対象のケースがありません (出力表示のみ)"))
        return 0
    if n_ac == n_total and judged_all and n_total > 0:
        submit = ""
        if url:
            m = re.fullmatch(r"(.*/contests/[^/]+)/tasks/([\w\-]+)", url)
            if m:
                submit = f"{m.group(1)}/submit?taskScreenName={m.group(2)}"
        print(green(f"✓ 全 {n_total} ケース AC!") + "  提出はブラウザから → " + cyan(submit or url or ""))
        return 0
    print(red(f"✗ {n_ac}/{n_total} AC"))
    return 1


def cmd_fetch(args):
    rest = [a for a in args if not a.startswith("-")]
    src = pick_source(rest[0] if rest else None)
    contest = infer_contest(os.path.join(os.getcwd(), src))
    if not contest:
        die("パスからコンテストを推定できません")
    ensure_samples(contest, problem_letter(src), refetch=True)
    return 0


def cmd_new(args):
    if not args:
        die("使い方: atc new <コンテスト名> (例: atc new abc467)")
    contest = args[0].lower()
    cdir = contest_dir(contest)
    os.makedirs(cdir, exist_ok=True)
    template = os.path.join(BASE_DIR, "!template.cpp")

    letters = None
    try:
        slugs = fetch_task_slugs(contest)
        letters = sorted(slugs.keys())
        print(f"問題一覧: {', '.join(l.upper() for l in letters)}")
    except SystemExit:
        raise
    except Exception as e:
        print(yellow(f"問題一覧を取得できませんでした ({e})"))
        print(yellow("コンテスト開始前かもしれません。a〜g を作成します。"))
        letters = list("abcdefg")

    for l in letters:
        dst = os.path.join(cdir, f"{l}.cpp")
        if os.path.exists(dst):
            continue
        if os.path.exists(template):
            with open(template, encoding="utf-8") as f:
                content = f.read()
        else:
            content = "#include <bits/stdc++.h>\nusing namespace std;\n\nint main(void) {\n\n}\n"
        with open(dst, "w", encoding="utf-8") as f:
            f.write(content)
    print(green(f"作成完了: {cdir}"))

    # サンプルを事前取得 (取れる問題だけ)
    cwd = os.getcwd()
    os.chdir(cdir)
    try:
        for l in letters:
            try:
                ensure_samples(contest, l)
            except Exception as e:
                print(yellow(f"  {l.upper()}: サンプル取得失敗 ({e})"))
    finally:
        os.chdir(cwd)
    print(f"cd {cdir}")
    return 0


def cmd_run(args):
    debug = "--debug" in args or "-d" in args
    rest = [a for a in args if not a.startswith("-")]
    src = pick_source(rest[0] if rest else None)
    binary = compile_cpp(src, debug=debug)
    print(dim(f"実行中: {binary} (入力はターミナルから / Ctrl+D で終了)"))
    return subprocess.run([binary]).returncode


def cmd_open(args):
    rest = [a for a in args if not a.startswith("-")]
    src = pick_source(rest[0] if rest else None)
    contest = infer_contest(os.path.join(os.getcwd(), src))
    if not contest:
        die("パスからコンテストを推定できません")
    letter = problem_letter(src)
    url = problem_url(letter)
    if not url:
        slug = get_slug(contest, letter)
        url = f"{BASE_URL}/contests/{contest}/tasks/{slug}"
    print(url)
    for opener in (["wslview"], ["powershell.exe", "-NoProfile", "-Command", "Start-Process"],):
        try:
            subprocess.run([*opener, url], check=True,
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            return 0
        except (OSError, subprocess.CalledProcessError):
            continue
    print(yellow("ブラウザを開けませんでした。上の URL を手動で開いてください。"))
    return 0


def cmd_stress(args):
    rest = [a for a in args if not a.startswith("-")]
    if len(rest) < 3:
        die("使い方: atc stress <解法.cpp> <愚直.cpp> <生成器.py> [回数=200]")
    sol, naive, gen = rest[0], rest[1], rest[2]
    iters = int(rest[3]) if len(rest) > 3 else 200
    b_sol = compile_cpp(sol)
    b_naive = compile_cpp(naive)
    for i in range(1, iters + 1):
        g = subprocess.run([sys.executable, gen, str(i)], capture_output=True)
        if g.returncode != 0:
            die(f"生成器がエラー終了しました:\n{g.stderr.decode('utf-8', 'replace')}")
        data = g.stdout
        r1 = subprocess.run([b_sol], input=data, capture_output=True, timeout=10)
        r2 = subprocess.run([b_naive], input=data, capture_output=True, timeout=60)
        o1 = r1.stdout.decode("utf-8", "replace")
        o2 = r2.stdout.decode("utf-8", "replace")
        ok, _ = outputs_match(o2, o1)
        if r1.returncode != 0 or not ok:
            print(red(f"\n✗ 反例発見 (seed={i})"))
            show_block("入力:", data.decode("utf-8", "replace"))
            show_block(f"愚直 ({naive}):", o2)
            show_block(f"解法 ({sol}):", o1)
            with open("stress_fail.in", "wb") as f:
                f.write(data)
            print(dim("入力を stress_fail.in に保存しました"))
            return 1
        print(f"\r  {i}/{iters} OK", end="", flush=True)
    print(green(f"\n✓ {iters} 回一致。反例なし"))
    return 0


def cmd_login(_args):
    print("開催中のコンテストのサンプル取得にはログインセッションが必要です。")
    print("1. ブラウザで https://atcoder.jp にログイン")
    print("2. F12 → アプリケーション → Cookie → REVEL_SESSION の値をコピー")
    print("3. 下に貼り付けて Enter")
    try:
        value = input("REVEL_SESSION: ").strip()
    except (EOFError, KeyboardInterrupt):
        print()
        return 1
    if not value:
        die("値が空です")
    os.makedirs(os.path.dirname(SESSION_FILE), exist_ok=True)
    with open(SESSION_FILE, "w") as f:
        f.write(value + "\n")
    os.chmod(SESSION_FILE, 0o600)
    print(green(f"保存しました: {SESSION_FILE}"))
    return 0


def cmd_help(_args=None):
    print(f"""{bold('atc — AtCoder ローカルテスト支援ツール')}

  {cyan('atc test [file] [-d|--debug] [-r|--refetch]')}
      サンプルを自動取得してコンパイル & 全ケース照合 ({bold('Ctrl+Space')})
      file 省略時はカレントで最後に編集した .cpp
  {cyan('atc new <contest>')}      コンテスト用ディレクトリ作成 + 全サンプル事前取得
                         (例: atc new abc467)
  {cyan('atc fetch [file]')}       サンプルを再取得
  {cyan('atc run [file] [-d]')}    コンパイルして手入力で実行 (従来の run 相当)
  {cyan('atc open [file]')}        問題ページをブラウザで開く
  {cyan('atc stress <解法> <愚直> <生成器.py> [回数]')}
                         ランダムテストで反例探し
  {cyan('atc login')}              開催中コンテスト用のセッション設定

  自作ケース: tests/<問題>/ に好きな名前.in / .out を置くと一緒に照合されます
  環境変数:   ATC_TL=実行制限秒(既定2)  ATC_EPS=誤差許容(既定1e-6)""")
    return 0


COMMANDS = {
    "test": cmd_test, "t": cmd_test,
    "new": cmd_new, "n": cmd_new,
    "fetch": cmd_fetch, "f": cmd_fetch,
    "run": cmd_run,
    "open": cmd_open, "o": cmd_open,
    "stress": cmd_stress,
    "login": cmd_login,
    "help": cmd_help, "-h": cmd_help, "--help": cmd_help,
}


def main():
    argv = sys.argv[1:]
    if not argv:
        return cmd_test([])
    cmd, *rest = argv
    if cmd in COMMANDS:
        return COMMANDS[cmd](rest)
    # `atc a.cpp` のようにファイル名を直接渡した場合は test 扱い
    if cmd.endswith(".cpp") or os.path.exists(cmd + ".cpp"):
        return cmd_test(argv)
    print(red(f"不明なコマンド: {cmd}"))
    cmd_help()
    return 2


if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        print()
        sys.exit(130)
    except RuntimeError as e:
        die(str(e))
    except urllib.error.URLError as e:
        die(f"通信エラー: {e}")
