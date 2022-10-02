CC = gcc
GCOV=-fprofile-arcs -ftest-coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm
  OPEN=xdg-open
else
  LIBS=-lcheck
  OPEN=open
endif

default: all

all: clean my_string.a test gcov_report

test: my_string.a 
	$(CC) test.c my_string.a $(LIBS) -o test.out -std=c11 -Wall -ggdb3
	./test.out

gcov_report: my_string.a
	$(CC) $(GCOV) test.c my_string.c $(LIBS) -o GCOV_rep.out
	./GCOV_rep.out
	lcov -t "GCOV_rep" -o GCOV_rep.info -c -d . 
	genhtml -o report GCOV_rep.info

my_string.a: 
	$(CC) -c my_string.c -o my_string.o
	ar rcs my_string.a my_string.o

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.out report *.dSYM


leaks: test
	CK_FORK=no leaks --atExit -- ./test.out
	make clean
	
codestyle:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem my_string.c *.c *.h

