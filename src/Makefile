CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17

all: clean check_style test gcov_report

test: clean
	$(CC) $(CFLAGS) --coverage tests/*.cc -lgtest -pthread -o test
	./test

gcov_report: test
	@lcov -t "test_containers" -o s21_containers.info -c -d . --ignore-errors mismatch,inconsistent
	@lcov -e s21_containers.info -o s21_containers_filtered.info
	@genhtml -o gcov_report s21_containers_filtered.info
	@open ./gcov_report/index.html

clean:
	@rm -rf test *.gcda *.gcno *.o *.info *.a test.dSYM a.out gcov_report

check_style:
	clang-format -style=Google -n *.cc *.h containers/*.h
	#clang-format -style=Google -n tests/*.cc

beautify:
	clang-format -style=Google -i *.cc *.h containers/*.h
	#clang-format -style=Google -i tests/*.cc

valgrind:
	CK_FORK=no valgrind --leak-check=full --tool=memcheck --leak-check=yes make test

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	brew install lcov

rebuild: clean test