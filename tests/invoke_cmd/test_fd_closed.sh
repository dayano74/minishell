#!/bin/bash

TARGET="./minishell"

has_noninherited_fd() {
    local log="$1"
    local prev_line

    while IFS= read -r line; do
        # "Open file descriptor" を見つけたら次の行をチェック
        if [[ "$line" == *"Open file descriptor"* ]]; then
            read -r next_line || break
            if [[ "$next_line" != *"<inherited from parent>"* ]]; then
                return 1  # NG
            fi
        fi
    done < "$log"

    return 0  # OK（inheritedなものしかなかった）
}


run_test() {
    name="$1"
    input="$2"
    LOG="$(mktemp)"

    echo -n "$name ... "

    echo -e "$input" | valgrind --track-fds=yes --log-file="$LOG" "$TARGET" > /dev/null

    if has_noninherited_fd "$LOG"; then
        echo "OK"
    else
        echo "NG"
        grep -A 1 "Open file descriptor" "$LOG"
    fi
}

echo "== FD Leak Test =="

run_test "test1: Ctrl+D で終了" ""
run_test "test2: exit コマンドで終了" "exit"
run_test "test3: echo hello → exit" "echo hello\nexit"
run_test "test4: ls | cat → exit" "ls | cat\nexit"
run_test "test5: echo 1 | cat | wc → exit" "echo 1 | cat | wc\nexit"
