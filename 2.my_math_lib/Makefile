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

all: clean my_math.a test gcov_report

test: my_math.a
	$(CC) test.c my_math.a $(LIBS) -o test.out
	./test.out

gcov_report: my_math.a
	$(CC) $(GCOV) test.c my_math.c $(LIBS) -o GCOV_rep.out
	./GCOV_rep.out
	lcov -t "GCOV_rep" -o GCOV_rep.info -c -d .
	genhtml -o report GCOV_rep.info

my_math.a:
	$(CC) -c my_math.c -o my_math.o
	ar rcs my_math.a my_math.o

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.out report


leaks: test
	CK_FORK=no leaks --atExit -- ./test.out
	make clean

codestyle:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem my_string.c *.c *.h

openreport:
	open report/index.html
