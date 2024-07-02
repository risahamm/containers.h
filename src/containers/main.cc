#include <iostream>

#include "s21_list.h"

using namespace std;

int main() {
    cout << endl << endl << "OUTPUT:" << endl;

    s21::List<int> lst;

    cout << "Added to list:" << endl;

    lst.push_front(5);
    lst.push_front(10);
    lst.push_front(15);
    for (int i = 0; i < lst.GetSize(); i++){
    cout << lst[i] << endl;}

    cout << "Size = " << lst.GetSize() << endl;


    cout << "Inserted one value:" << endl;

    lst.insert(20, 1);
    for (int i = 0; i < lst.GetSize(); i++){
        cout << lst[i] << endl;}

    cout << "Size = " << lst.GetSize() << endl;

    cout << "Clear" << endl;

    lst.clear();

    cout << "Size = " << lst.GetSize() << endl;

    return 0;
}

// clang-format -style=Google -i s21_list.h