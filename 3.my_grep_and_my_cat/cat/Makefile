GCC=gcc
WALL_WEXTRA_WERROR=-std=c11 -Wall -Wextra -Werror
SOURCES=my_cat
	
my_cat:
	$(GCC) $(WALL_WEXTRA_WERROR) $(SOURCES).c -o $(SOURCES)

clean:
	rm -f *.o
	rm -f my_cat
	rm -f *.out

all: clean my_cat

test:
	./test.sh

style:
	python3 ../../materials/linters/cpplint.py --extensions=c *.c

check:
	cppcheck --enable=all --suppress=missingIncludeSystem my_cat.c *.c

leaks:
	leaks --atExit -- ./my_cat