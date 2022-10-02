CC 						= gcc -std=c11
OS 						= $(shell uname)

# flags #
CFLAG 					= #-Wall -Wextra -Werror
GCOV 					= --coverage

# libraries #
ifeq ($(OS), Linux)
	LIBS 				= -lcheck -lpthread -lrt -lm -lsubunit
	OPEN 				= xdg-open
else
	BREW_HOME 			= $(shell brew config | grep HOMEBREW_PREFIX | cut -d" " -f2)
	PATH-TO-CHECK 		= -I${BREW_HOME}/include
	PATH-TO-LIB-CHECK 	= -L${BREW_HOME}/Cellar/check/0.15.2/lib
	LIBS 				= -lcheck $(PATH-TO-CHECK) $(PATH-TO-LIB-CHECK)
	OPEN 				= open
endif

# path and files #
LIB_NAME 				= my_decimal.a

T_NAME					= my_decimal_test
T_SOURSE 				= $(T_NAME).c
T_HEADER 				= $(T_NAME).h
T_OBJECT 				= $(T_SOURCE:%.c=%.o)

SOURCES 				= $(filter-out $(T_SOURSE) my_decimal_test_us.c main.c, $(wildcard *.c))
HEADERS 				= $(filter-out $(T_HEADER), $(wildcard *.h))
OBJECTS 				= $(SOURCES:%.c=%.o)

# targets #
all: test

$(LIB_NAME): $(OBJECTS) $(HEADERS)
	@ar -rcs $(LIB_NAME) $?
	@ranlib $@
	@rm -rf *.o
	@echo "Successfully. The library was created."

# targets for tests #
test: $(LIB_NAME)
	@echo " "
	@$(CC) $(T_SOURSE) -o $(T_NAME) $(LIB_NAME) $(LIBS)
	@./$(T_NAME)

gcov_report:
	@$(CC) $(GCOV) $(T_SOURSE) $(SOURCES) $(LIBS) -o coverage
	@./coverage
	@lcov --no-external -o report.info -c -q -d .
	@genhtml --legend --title "my_decimal" report.info -o report
	@rm -rf *.gcda *.gcno *.gz *.out *.info coverage

# assembly #
clean:
	@rm -rf *.o *.a *.gcno *.gcda *.info *.out coverage report $(T_NAME)
	@echo "Successfully. Everything was deleted."

rebuild: clean all

openreport:
	$(OPEN) report/index.html

# for debug #
check: codestyle cppcheck

codestyle:
	@echo "------------  Linter  ---------------"
	@python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	@echo "------------  CPPCheck  -------------"
	@cppcheck --enable=warning --suppress=missingIncludeSystem *.c *.h

ifeq ($(OS), Linux)
valg:
	@echo "------------  Valgrind  -------------"
	@CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(T_NAME)

else
leaks:
	@echo "-------------  Leaks  ---------------"
	@CK_FORK=no leaks --atExit -- ./$(T_NAME)
endif