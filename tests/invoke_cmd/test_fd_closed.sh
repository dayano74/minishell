#!/bin/bash

TARGET="./minishell"

run_test() {
    name="$1"
    input="$2"
    LOG="$(mktemp)"

    echo -n "$name ... "

    echo -e "$input" | valgrind --track-fds=yes --log-file="$LOG" "$TARGET" > /dev/null

    if grep -q "FILE DESCRIPTORS: [1-9]" "$LOG"; then
        echo "NG"
        grep -A 5 "FILE DESCRIPTORS:" "$LOG"
    else
        echo "OK"
    fi
}

echo "== FD Leak Test =="

run_test "test1: Ctrl+D で終了" ""
run_test "test2: exit コマンドで終了" "exit"
run_test "test3: echo hello → exit" "echo hello\nexit"
run_test "test4: ls | cat → exit" "ls | cat\nexit"
run_test "test5: echo 1 | cat | wc → exit" "echo 1 | cat | wc\nexit"
