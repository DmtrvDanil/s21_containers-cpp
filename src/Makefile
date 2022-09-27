CC=gcc
CFLAGS=-lstdc++ -lgtest -std=c++17 -g

all: test

test: tests.cpp
	@${CC} $<  ${CFLAGS} -o $@
	@./test

gcov_report: tests.cpp
	@$(CC) --coverage $< ${CPPFLAGS} ${CHECKFLAGS} -o $@
	@./$@
	@lcov -t "$@" -o $@.info -c -d ./
	@genhtml -o report $@.info

clean:
	@/bin/rm -rf *.o *.a test *.gcno *gcda report *.info main *.dSYM *.out gcov_report

style:
	python3 ../materials/linters/cpplint.py --extensions=tpp *.tpp *.h

cppcheck:
	cppcheck --enable=all --suppress=useStlAlgorithm --suppress=missingIncludeSystem . *.tpp *.cpp

leaks: test
	leaks --atExit -- ./$<

rebuild: clean all
