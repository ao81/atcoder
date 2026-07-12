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
if [[ $- == *i* ]]; then
    bind -x '"\C-@": __atc_auto'
    bind -x '"\e[32;6u": __atc_manual'
fi
