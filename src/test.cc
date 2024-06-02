#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
  vector<int> b = {1, 2, 3, 4, 5};
  //  s21::Vector<int> b = {1, 2, 3, 4, 5};

  b.reserve(10);

  for (int i = 0; i < b.size(); i++) {
    std::cout << b[i] << std::endl;
  }

  cout << "size = " << b.size() << endl;
  cout << "capacity = " << b.capacity() << endl << endl;
  //  cout << "______________________" << endl;

  return 0;
}