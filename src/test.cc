#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
  vector<int> a;
  //  a.push_back(1);
  //  a.push_back(2);
  //  a.push_back(3);
  //  a.push_back(4);
  //  a.push_back(5);
  //    cout << a.at(0) << endl;
  //  cout << a.at(3) << endl;
//  cout << "size = " << a.size() << endl;
//  cout << "capacity = " << a.capacity() << endl;
  //  a[18] = 18;
//  cout << a[0] << endl;
  //  cout << a[3] << endl;
  //  cout << a[18] << endl;

    s21::Vector<int> my(4);
    cout << "size = " << my.size() << endl;
    cout << "capacity = " << my.capacity() << endl;
    my.at(1) = 25;
    cout << "my.at = " << my[1] << endl;

  return 0;
}