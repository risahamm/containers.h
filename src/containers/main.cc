#include <iostream>

#include "s21_list.h"

using namespace std;

int main() {
    cout << endl << endl << "OUTPUT:" << endl;

    s21::List<int> lst = {1, 2, 3};
//    int x = 5, y = 3;
//    lst.push_back(x);
//    lst.push_back(y);
//    lst.push_front(x);
//    lst.pop_front();

    s21::List<int>::ListIterator<int> It = lst.begin();
    It++;
//    lst.insert(It, 4);

    cout << "SIZE = " << lst.size() << endl;
    cout << "LIST:" << endl;
    for (int i = 1; i != lst.size() + 1; i ++) {
        cout << lst[i] << endl;
    }

    return 0;
}

// clang-format -style=Google -i s21_list.h