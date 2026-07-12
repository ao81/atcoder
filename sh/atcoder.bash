# AtCoder ツール設定 (~/.bashrc から source される)
alias atc="$HOME/atcoder/sh/atc"

# Ctrl+Space: 自動テスト (サンプル取得 + コンパイル + 全ケース照合)
__atc_auto() {
    echo
    "$HOME/atcoder/sh/atc" test
}
# Ctrl+Shift+Space: 手動テスト (コンパイルして手入力で実行)
# 注: 多くのターミナルは Ctrl+Space と区別できず両方 NUL を送るため自動側が動く。
#     VS Code 内では VS Code のキーバインドが両方を捕捉するので正しく分かれる。
#     CSI-u (拡張キーボードプロトコル) 対応ターミナルなら区別可能。
__atc_manual() {
    echo
    "$HOME/atcoder/sh/atc" run
}
# Ctrl+N: 新規コンテスト作成 (コンテスト名と問題を聞いて作成 → cd)
# 注: readline の next-history (Ctrl+N) を上書きする。履歴移動は下矢印で。
__atc_new() {
    echo
    local contest letters
    read -e -p "コンテスト名 (例: abc467): " contest || return
    [ -z "$contest" ] && return
    read -e -p "作成する問題 (例: 4 / a-d / abd, 空=自動): " letters
    "$HOME/atcoder/sh/atc" new "$contest" $letters || return
    local dir
    dir=$("$HOME/atcoder/sh/atc" dir "$contest" 2>/dev/null) && [ -d "$dir" ] && cd "$dir"
}
if [[ $- == *i* ]]; then
    bind -x '"\C-@": __atc_auto'
    bind -x '"\e[32;6u": __atc_manual'
    bind -x '"\C-n": __atc_new'
fi
