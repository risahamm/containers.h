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
    for (int i = 0; i < lst.getSize(); i++){
    cout << lst[i] << endl;}

    cout << "Size = " << lst.getSize() << endl;


    cout << "Inserted one value:" << endl;

    lst.insert(20, 1);
    for (int i = 0; i < lst.getSize(); i++){
        cout << lst[i] << endl;}

    cout << "Size = " << lst.getSize() << endl;

    cout << "Pop back:" << endl;

    lst.pop_back();
    for (int i = 0; i < lst.getSize(); i++){
        cout << lst[i] << endl;}

    cout << "Size = " << lst.getSize() << endl;

    cout << "Clear" << endl;

    lst.clear();

    cout << "Size = " << lst.getSize() << endl;

    return 0;
}

// clang-format -style=Google -i s21_list.h