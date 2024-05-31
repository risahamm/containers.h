#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {

//  vector<int> b;
    s21::Vector<int> b;

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  b.push_back(1);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
  }

  b.push_back(2);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
  }

  b.push_back(3);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
  }

  b.push_back(4);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
  }

  b.push_back(5);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
  }

  b.push_back(6);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;

  cout << "______________________" << endl;
  for (int i = 0; i < b.capacity(); ++i) {
    cout << b[i] << endl;
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