all:
	gcc -g maze2.c -lncurses
	./a.out

g:
	gcc -g maze2.c -lncurses
	gdb --tui ./a.out
