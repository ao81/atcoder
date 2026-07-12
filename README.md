# atcoder

## 使い方 (atc ツール)

**VS Code で `Ctrl+Space`** → 開いている .cpp をサンプル自動取得 → コンパイル → 全ケース照合 (自動テスト)。
**VS Code で `Ctrl+Shift+Space`** → コンパイルして手入力で実行 (手動テスト)。

ターミナル (bash) では `Ctrl+Space` = 自動テスト。最後に編集した .cpp が対象。
(通常のターミナルは Ctrl+Shift+Space を Ctrl+Space と区別できないため、
手動テストはコマンド `atc run` で。VS Code 内では両キーとも正しく動く)

`Ctrl+N` = 新規コンテスト作成 (コンテスト名と問題を聞いて作成)。

```
atc test [file] [-d] [-r]   サンプル取得 + コンパイル + 全ケース照合 (Ctrl+Space と同じ)
                            -d: sanitizer 付きデバッグビルド  -r: サンプル再取得
atc new abc467 [問題]       コンテスト用フォルダ作成 + サンプル事前取得 (Ctrl+N と同じ)
                            問題: 4 / a-d / abd など。省略時は問題一覧から自動
atc run [file]              コンパイルして手入力で実行 (従来の run 相当)
atc open [file]             問題ページをブラウザで開く
atc stress <解法> <愚直> <生成器.py> [回数]
                            ランダムテストで反例探し (反例は stress_fail.in に保存)
atc login                   開催中コンテスト用に REVEL_SESSION を設定
atc help                    ヘルプ
```

- サンプルは `tests/<問題>/1.in / 1.out` にキャッシュされる (git 管理外)
- `tests/<問題>/` に自作の `好きな名前.in / .out` を置くと一緒に照合される
  (`.out` が無い `.in` は出力表示のみ)
- 照合は行末空白・空白量の差を無視。数値は相対/絶対誤差 1e-6 まで許容 (`ATC_EPS` で変更)
- 実行制限は 2 秒 (`ATC_TL=4 atc test` などで変更)
- ソース内に `atcoder/` があれば ac-library を、`gmpxx.h` があれば GMP を自動リンク
- テンプレート [`!template.cpp`](!template.cpp) には chmin/chmax・vector 一括入出力
  (`cin >> v` / `cout << v`)・`yesno(bool)`・`dbg(...)` 付き。
  `dbg()` はローカル専用 (atc が `-DLOCAL` を付与)。提出コードに残してもジャッジでは無効
- **提出だけは reCAPTCHA の関係で手動**: 全 AC 時に提出ページの URL が表示される

VS Code のタスク (`Ctrl+Space` = 既定ビルドタスク) は [.vscode/tasks.json](.vscode/tasks.json)、
本体は [sh/atc.py](sh/atc.py)、シェル設定は [sh/atcoder.bash](sh/atcoder.bash)。

### stress 用生成器の例 (gen.py)

```python
import random, sys
random.seed(int(sys.argv[1]))
n = random.randint(1, 8)
print(n)
print(*[random.randint(-10, 10) for _ in range(n)])
```

## 参考サイト

[Atcoder Problems](https://kenkoooo.com/atcoder/#/table/)  

[環境構築 (C++&VSCode)](https://qiita.com/sorachandu/items/a06e4ed61d169ba067f3#wsl%E3%81%AE%E5%B0%8E%E5%85%A5-windows%E3%83%A6%E3%83%BC%E3%82%B6%E3%81%AE%E3%81%BF)

[AtCoder NoviSteps](https://atcoder-novisteps.vercel.app/)
