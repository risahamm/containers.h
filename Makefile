CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17

check_style:
	clang-format -style=Google -n *.cc *.h
	clang-format -style=Google -n tests/*.cc

beautify:
	clang-format -style=Google -i *.cc *.h
	clang-format -style=Google -i tests/*.cc

valgrind:
	CK_FORK=no valgrind --leak-check=full --tool=memcheck --leak-check=yes make test

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	brew install lcov

rebuild: clean test