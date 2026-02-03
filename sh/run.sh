#! /bin/bash

# --- 設定エリア ---
BASE_DIR="$HOME/atcoder"
IN_FILE="$BASE_DIR/sh/in.txt"
OUT_FILE="$BASE_DIR/sh/out.txt"

TEMP_NAME="${1:-main}"
SOURCE_FILE="${TEMP_NAME%.cpp}.cpp" # 引数1: ソースファイル名 (省略時はmain.cpp)
MODE="$2"                    # 引数2: debug または terminal または 保存名

# 入力ファイルがなければ作成
if [ ! -f "$IN_FILE" ]; then touch "$IN_FILE"; fi

# --- 1. コンパイルセクション ---
echo "--- Compiling $SOURCE_FILE ---"

CXX_FLAGS="-std=gnu++20 -O2 -Wall -Wextra"
LINK_FLAGS=""

# ACL (AtCoder Library) の自動判別
if grep -q "atcoder/" "$SOURCE_FILE"; then
    # 作業ディレクトリまたは固定パスのACLを指定
    CXX_FLAGS+=" -I$BASE_DIR/ac-library"
fi

# GMP (多倍長整数) の自動判別
if grep -q "gmpxx.h" "$SOURCE_FILE"; then
    LINK_FLAGS+=" -lgmpxx -lgmp"
fi

# デバッグモード判定
if [ "$MODE" = "debug" ]; then
    echo "[Mode: Debug Enabled]"
    CXX_FLAGS+=" -fsanitize=address -fsanitize=undefined -g"
fi

# コンパイル実行
if g++ $CXX_FLAGS "$SOURCE_FILE" $LINK_FLAGS -o a.out; then
    echo "Compilation: OK"
else
    echo "Compilation: FAILED"
    exit 1
fi

# --- 2. 実行セクション ---
echo "--- Running ---"

if [ "$MODE" = "terminal" ]; then
    # 画面に直接出力
    ./a.out < "$IN_FILE"
else
    # ファイルに出力しつつ、画面にも「終わったよ」と表示
    ./a.out < "$IN_FILE" > "$OUT_FILE"
    echo "Result saved to: $OUT_FILE"
    
    # もし MODE に特定の名前（debug/terminal以外）が入っていたら、その名前でも保存
    if [ -n "$MODE" ] && [ "$MODE" != "debug" ]; then
        cp "$OUT_FILE" "$MODE.txt"
        echo "Copy saved to: $MODE.txt"
    fi
fi

echo "--- Done ---"