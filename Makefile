FLAGS=-Wall -Werror -Wextra -std=c++17
COVERAGE=
UNAME:=$(shell uname -s)

.PHONY: all clean test add_coverage gcov_report

all: clean proj_matrix_oop.a
deafult: all

proj_matrix_oop.o: *.cpp
	g++ $(FLAGS) -c $^

proj_matrix_oop.a: proj_matrix_oop.o
	ar rvs proj_matrix_oop.a *.o

clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda proj_test report

test: clean proj_matrix_oop.a
	g++ $(FLAGS) $(COVERAGE) test/test.cpp test/functions/*.cpp proj_matrix_oop.a -o proj_test -lgtest
	./proj_test

add_coverage:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage test
	./proj_test
	gcov -b -l -p -c proj_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter proj_matrix_oop.cpp
	xdg-open gcov_report.html

style_test:
	find . -name "*.cpp" -or -name "*.h" -or -name "*.c" | xargs clang-format -n

style_edit:
	find . -name "*.cpp" -or -name "*.h" -or -name "*.c" | xargs clang-format -i

valgrind: test
	valgrind --leak-check=full ./proj_test
