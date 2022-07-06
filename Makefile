all: clean test s21_string.a

s21_string.a: s21_string.o
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a
	
s21_string.o: s21_string.c s21_string.h s21_strerror.h
	gcc -Wall -Werror -Wextra -std=c11 -c s21_string.c
	
s21_string_testc.o: s21_string_testc.c
	gcc -c s21_string_testc.c -g

test: s21_string.a s21_string_testc.o
	gcc -Wall -Werror -Wextra s21_string_testc.o s21_string.a -o tests -lcheck --coverage
	./tests

gcov_report:
	gcc -c -fprofile-arcs -ftest-coverage s21_string.c
	gcc -Wall -fprofile-arcs s21_string_testc.o s21_string.o -o tests -lcheck
	./tests
	gcov -f s21_string.gcda
	gcovr -r . --html --html-details -o coverage_report.html
	rm s21_string.o
	open coverage_report.html

lcov_report:
	gcc --coverage s21_string_testc.c -o s21_string_test s21_string.c `pkg-config --cflags --libs check`
	./s21_string_test
	lcov -t "s21_string_test" -o s21_string_test.info -c -d .
	genhtml -o report s21_string_test.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_string_test s21_string_test.info

clean:
	rm -f *.o *.a *.css *.html *.gcno *.gcda *.gcov tests

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./tests
	
memory:
	CK_FORK=no leaks --atExit -- ./tests
	rm -rf s21_string.o