# usage
# make -f testexit.mk
# make -f testexit.mk clean

all:
	cc tests/builtin/test_exit.c src/builtin/exit.c -Ilib/libft -Llib/libft -lft -Iinc -lreadline -o test_exit

clean:
	rm -f test_exit
