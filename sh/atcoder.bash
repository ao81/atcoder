# AtCoder ツール設定 (~/.bashrc から source される)
alias atc="$HOME/atcoder/sh/atc"

# Ctrl+Space: カレントディレクトリの最新 .cpp をサンプル照合テスト
__atc_ctrl_space() {
    echo
    "$HOME/atcoder/sh/atc" test
}
if [[ $- == *i* ]]; then
    bind -x '"\C-@": __atc_ctrl_space'
fi
