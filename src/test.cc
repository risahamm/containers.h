#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
//      vector<int> f;
//      f.push_back(1);
//      f.push_back(2);
//      f.push_back(3);
//      std::vector<int>::iterator p = f.end();
//      *p = 44;
//      cout << "f = " << *p << endl;

  s21::Vector<int> a(3);
  cout << "object a " << &a << endl;
  a[0] = 11;
  a[1] = 22;
  a[2] = 33;
  cout << "object a[0] " << &a[0] << endl;
  cout << "object a[1] " << &a[1] << endl;
  cout << "object a[2] " << &a[2] << endl;

  int *p = a.end();
  cout << "object p " << p << endl;
  *p = 44;
  cout << "begin = " << *p << endl;
  delete[] p;
  return 0;
}