#include <iostream>

#include "s21_list.h"

using namespace std;

int main() {
    cout << endl << endl << "OUTPUT:" << endl;

    s21::List<int> lst = {5, 6};
    s21::List<int> lst2 = {1, 2, 3};


//    s21::List<int>::ListIterator<int> It = lst.begin();
//    It++;
//    lst.insert(It, 4);
    lst.merge(lst2);

    cout << "SIZE = " << lst.size() << endl;
    cout << "LIST:" << endl;
    for (size_t i = 1; i != lst.size() + 1; i ++) {
        cout << lst[i] << endl;
    }
    cout << "LIST2:" << endl;
    for (size_t i = 1; i != lst2.size() + 1; i ++) {
        cout << lst2[i] << endl;
    }

    return 0;
}

// clang-format -style=Google -i s21_list.h