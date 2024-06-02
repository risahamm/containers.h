#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
  //  vector<int> b = {1, 2, 3, 4, 5};
  s21::Vector<int> b(10);
  b.push_back(1);
  b.push_back(2);
  b.push_back(3);

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl;
  cout << "______________________" << endl;

  b.shrink_to_fit();

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl;

  //  for (int i = 0; i < b.size(); i++) {
  //    std::cout << b[i] << std::endl;
  //  }

  //  cout << "size = " << b.size() << endl;
  //  cout << "capacity = " << b.capacity() << endl << endl;
  //  cout << "______________________" << endl;

  return 0;
}