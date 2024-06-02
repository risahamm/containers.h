#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {

//  vector<int> b = {1, 2, 3, 4, 5};
    s21::Vector<int> b = {1, 2, 3, 4, 5};
//
////  cout << "size = " << b.size() << endl;
////  cout << "capacity = " << b.capacity() << endl << endl;
//
//  int v = 1;
//
//  for (int k = 0; k < 6; ++k) {
//    b.push_back(v);
//    cout << "size = " << b.size() << endl;
//    cout << "capacity = " << b.capacity() << endl;
//    cout << "______________________" << endl;
//    for (int i = 0; i < b.size(); ++i) {
//      cout << b[i] << endl;
//    }
//    ++v;
//  }

  for(int i = 0; i < b.size(); i++) {
    cout << b[i] << endl;
  }
  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;
  cout << "______________________" << endl;
  b.pop_back();
  b.pop_back();
  b.pop_back();
  b.push_back(8);
  for(int i = 0; i < b.size(); i++) {
    cout << b[i] << endl;
  }
  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;
  return 0;
}