#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {

//  vector<int> b;
    s21::Vector<int> b;

//  cout << "size = " << b.size() << endl;
//  cout << "capacity = " << b.capacity() << endl << endl;

  int v = 1;

  for (int k = 0; k < 10; ++k) {
    b.push_back(v);
    cout << "size = " << b.size() << endl;
    cout << "capacity = " << b.capacity() << endl;
    cout << "______________________" << endl;
    for (int i = 0; i < b.size(); ++i) {
      cout << b[i] << endl;
    }
    ++v;
  }

//  s21::Vector<int> a(3);
//  a[0] = 1;
//  a[1] = 2;
//
//  cout << a.size() << endl << endl;
//
//  a.insert(a.end(), 9);
//
//  cout << a.size() << endl << endl;
//
//  for (int i = 0; i < a.size(); ++i) {
//    cout << a[i] << endl;
//  }


  return 0;
}