#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
//      vector<int> f;
//      f.push_back(1);
//      f.push_back(2);
//      f.push_back(3);
//
//      cout << "size " << f.size() << endl;
//      cout << "capacity " << f.capacity() << endl << endl;
//
//      cout << f[0] << endl;
//      cout << f[1] << endl;
//      cout << f[2] << endl << endl;
//
//      f.erase(f.begin());
//
//      cout << "size " << f.size() << endl;
//      cout << "capacity " << f.capacity() << endl << endl;
//
//      cout << f[0] << endl;
//      cout << f[1] << endl;
//      cout << f[2] << endl;

//s21::Vector<int> a(5);
//a[0] = 11;
//a[1] = 22;
//a[2] = 33;
//a[3] = 44;
//a[4] = 55;
////int *p = a.begin();
//a.erase(a.begin());

/* end() */// ------------------------------
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
  delete p;
// -------------------------------------------
//  int str[6] = {1, 2, 3, 4, 5};
//  int str2[5] = {0};
//  int *p = &str[4];
////  int *end = &str[4+1];
//  int j = 0;
//  for (int *i = str; *i != '\0'; i++) {
//    if(i == p) continue;
//    str2[j] = *i;
//    j++;
//  }
//
//  for (int i = 0; i < 5; i++) {
//    cout << str2[i] << endl;
//  }
  return 0;
}