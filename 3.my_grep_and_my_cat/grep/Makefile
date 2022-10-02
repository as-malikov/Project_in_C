GCC=gcc
WALL_WEXTRA_WERROR=-std=c11 -Wall -Wextra -Werror
SOURCES=my_grep
	
my_grep:
	$(GCC) $(WALL_WEXTRA_WERROR) $(SOURCES).c -o $(SOURCES)

clean:
	rm -f *.o
	rm -f my_grep

all: clean my_grep

test:
	./test.sh

style:
	python3 ../../materials/linters/cpplint.py --extensions=c *.c

check:
	cppcheck --enable=all --suppress=missingIncludeSystem my_grep.c *.c

leaks:
	leaks --atExit -- ./my_grep