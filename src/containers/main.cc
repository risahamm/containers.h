#include <iostream>

#include "s21_list.h"

using namespace std;

int main() {
    cout << endl << endl << "OUTPUT:" << endl;

    s21::List<int> lst;
    int x = 5, y = 3;
    lst.push_back(x);
    lst.push_back(y);
    lst.push_front(x);
    lst.pop_front();

    cout << lst.size() << endl;



    return 0;
}

// clang-format -style=Google -i s21_list.h