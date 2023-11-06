FLAGS=-Wall -Werror -Wextra -std=c++17
COVERAGE=
UNAME:=$(shell uname -s)

.PHONY: all clean test add_coverage gcov_report

all: clean s21_matrix_oop.a
deafult: all

s21_matrix_oop.o: *.cpp
	g++ $(FLAGS) -c $^

s21_matrix_oop.a: s21_matrix_oop.o
	ar rvs s21_matrix_oop.a *.o

clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda s21_test report

test: clean s21_matrix_oop.a
	g++ $(FLAGS) $(COVERAGE) test/test.cpp test/functions/*.cpp s21_matrix_oop.a -o s21_test -lgtest
	./s21_test

add_coverage:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage test
	./s21_test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter s21_matrix_oop.cpp
	xdg-open gcov_report.html

style_test:
	find . -name "*.cpp" -or -name "*.h" -or -name "*.c" | xargs clang-format -n

style_edit:
	find . -name "*.cpp" -or -name "*.h" -or -name "*.c" | xargs clang-format -i

valgrind: test
	valgrind --leak-check=full ./s21_test
