#include <iostream>
#include <vector>

#include "s21_containers.h"

//using namespace std;

int main() {
  s21::Vector<int> b = {1, 2, 3, 4, 5};
  s21::Vector<int> a = {7, 6, 5, 4};

  b.swap(a);

  for (int i = 0; i < b.size(); i++) {
    std::cout << b[i] << std::endl;
  }
  std::cout << "______________________" << std::endl;
  for (int i = 0; i < a.size(); i++) {
    std::cout << a[i] << std::endl;
  }
//  cout << "size = " << b.size() << endl;
//  cout << "capacity = " << b.capacity() << endl << endl;
//  cout << "______________________" << endl;
//  cout << "size = " << a.size() << endl;
//  cout << "capacity = " << a.capacity() << endl << endl;
  return 0;
}