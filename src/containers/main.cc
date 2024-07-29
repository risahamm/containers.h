#include <iostream>

#include "s21_list.h"

using namespace std;

int main() {
    cout << endl << endl << "OUTPUT:" << endl;

    s21::List<int> lst = {5, 4, 3, 8, 9, 10, 2, 1, 6, 7};
    s21::List<int> lst2 = {1, 2, 3};


    s21::List<int>::ListIterator<int> It1 = lst.begin();
    s21::List<int>::ListIterator<int> It2 = lst2.begin();
//    It++;
//    lst.insert(It, 4);
//s21::List<int>::Node<int> *Node1 = It1.get_node();
//    s21::List<int>::Node<int> *Node2 = It2.get_node();
    lst.sort();


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