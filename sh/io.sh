#! /bin/bash

# ベースとなるディレクトリのパス（絶対パスで指定しておくとどこからでも動きます）
BASE_DIR="$HOME/atcoder"
IN_FILE="$BASE_DIR/sh/in.txt"
OUT_FILE="$BASE_DIR/sh/out.txt"

# もし sh/in.txt が存在しない場合は空のファイルを作成する
if [ ! -f "$IN_FILE" ]; then
    touch "$IN_FILE"
fi

# 実行
if [ $# == 0 ]; then
    # 引数なし：結果を sh/out.txt に保存
    ./a.out < "$IN_FILE" > "$OUT_FILE"
    echo "Executed: Result saved to sh/out.txt"
    exit 0
fi

if [ "$1" == "terminal" ]; then
    # 引数が terminal：結果を画面に表示
    ./a.out < "$IN_FILE"
    exit 0
fi

# 引数あり：結果を sh/out.txt に保存しつつ、指定された名前.txt にもコピー（以前の機能を維持）
./a.out < "$IN_FILE" > "$OUT_FILE"
cp "$OUT_FILE" "$1.txt"
echo "Executed: Result saved to sh/out.txt and $1.txt"