all:
	cc tests/builtin/test_pwd.c src/builtin/pwd.c -Llib/libft -lft -Iinc -o test_pwd

clean:
	rm -f test_pwd
