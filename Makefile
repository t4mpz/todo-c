GCC_FLAGS= -Wall -Wextra

lib:
	gcc $(GCC_FLAGS) -fsyntax-only todolib.c
parser:
	gcc $(GCC_FLAGS) -fsyntax-only argumentParser.c
dev:
	gcc $(GCC_FLAGS) -O2 todolib.c todo.c -o todo

