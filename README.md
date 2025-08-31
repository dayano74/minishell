# minishell

## 概要
- ttsubo, dayanoで進めているMinishellの開発リポジトリ
- このリポジトリはforkされたリポジトリです。オリジナルは[こちら](https://github.com/cacapon/minishell)です。
- 開発はGitHub Flowを用いて進め、ブランチ運用・レビューを行いました。

## minishellとは
- minishellとは、bashをC言語で再実装する42Tokyoの課題です。
- 基本的なシェル機能（コマンド実行、リダイレクト、パイプ、環境変数管理など）を低レイヤーのシステムコールを用いて構築します。

## 技術的要素（Tech Stack）
- C言語
- システムコール（fork, execve, pipe, dup2, waitなど）
- メモリ管理（malloc, free）
- GitHub Flowによるチーム開発
- バグ調査・デバッグ（gdb, valgrind）

## 役割・貢献（My Contribution）
- **コマンド実行処理全般**を担当し、外部コマンドの呼び出しやエラー処理を実装  
- **パイプ・リダイレクト機能**を担当し、複数コマンドの連携を可能にする仕組みを構築  
- **ビルトインコマンド**はペアと分担し、`echo`, `pwd`, `exit`などを担当  
- **レビューとテスト**を通じて品質向上に貢献  

（※パーサー部分はペアが担当）

## 協働・成果
- GitHub Flowに基づき、課題ごとにブランチを作成 → PR → 相互レビュー → mainへマージという流れを徹底  
- 担当機能を明確化しつつ、必要に応じて相互サポートを実施  
- 開発期間中に発生したバグやメモリリークも協力して解消し、bashの基本動作を再現することに成功  

## 学び・強み
- 低レイヤーの技術を用いたシステム実装経験  
- GitHub Flowによる実務に近いチーム開発経験  
- 課題を分担しつつ、協力して完成まで導いた問題解決力

## 実行方法
```
git clone git@github.com:dayano74/minishell.git
cd minishell
make
```
makeすると、`minishell`という実行ファイルが生成されます。
```
./minishell
```
`minishell`を実行すると、プロンプトが表示されます。ここからコマンドを入力して実行できます。
```
./minishell
$
$ echo "hello world"
hello world
$ touch file.txt
$ echo hi > file.txt
hi
total 112
-rw-r--r-- 1 dayano dayano  1064 Aug 31 19:20 LICENSE
-rw-r--r-- 1 dayano dayano  4327 Aug 31 19:20 Makefile
-rw-r--r-- 1 dayano dayano  1962 Aug 31 19:29 README.md
-rwxr-xr-x 1 dayano dayano   170 Aug 31 19:20 copy_to_subject.sh
-rw-r--r-- 1 dayano dayano     3 Aug 31 19:30 file.txt
drwxr-xr-x 8 dayano dayano  4096 Aug 31 19:20 inc
drwxr-xr-x 3 dayano dayano  4096 Aug 31 19:20 lib
-rwxr-xr-x 1 dayano dayano 65448 Aug 31 19:29 minishell
drwxr-xr-x 8 dayano dayano  4096 Aug 31 19:29 obj
drwxr-xr-x 7 dayano dayano  4096 Aug 31 19:20 src
-rw-r--r-- 1 dayano dayano  2296 Aug 31 19:20 test.mk
drwxr-xr-x 6 dayano dayano  4096 Aug 31 19:20 tests
$ cat file.txt
hi
total 112
-rw-r--r-- 1 dayano dayano  1064 Aug 31 19:20 LICENSE
-rw-r--r-- 1 dayano dayano  4327 Aug 31 19:20 Makefile
-rw-r--r-- 1 dayano dayano  1962 Aug 31 19:29 README.md
-rwxr-xr-x 1 dayano dayano   170 Aug 31 19:20 copy_to_subject.sh
-rw-r--r-- 1 dayano dayano     3 Aug 31 19:30 file.txt
drwxr-xr-x 8 dayano dayano  4096 Aug 31 19:20 inc
drwxr-xr-x 3 dayano dayano  4096 Aug 31 19:20 lib
-rwxr-xr-x 1 dayano dayano 65448 Aug 31 19:29 minishell
drwxr-xr-x 8 dayano dayano  4096 Aug 31 19:29 obj
drwxr-xr-x 7 dayano dayano  4096 Aug 31 19:20 src
-rw-r--r-- 1 dayano dayano  2296 Aug 31 19:20 test.mk
drwxr-xr-x 6 dayano dayano  4096 Aug 31 19:20 tests
$ ls -la | wc -l
18
$ cat << EOF
> hi
> hello
> bye
> EOF
hi
hello
bye
$ exit
exit
```