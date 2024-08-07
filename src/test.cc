#include <iostream>
#include <set>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
//    multiset<int> a;
  //  a.insert(40);
  //  a.insert(10);
  //  a.insert(20);
  //  a.insert(15);
  //  a.insert(90);
  //  a.insert(5);
  //  a.insert(60);
  //  a.insert(70);
  //  a.insert(50);
  //  a.insert(45);
  //
  //  auto p1 = a.equal_range(70);
  //
  //  cout << "p1 " << *p1.first << endl;
  //  cout << "p1 " << *p1.second << endl;

  s21::Multiset<int> b;
  s21::Multiset<int> my;
  my.insert(6);
  my.insert(3);
  auto my_it = my.insert(9);
  my.insert(1);
  my.insert(4);
  my.insert(9);
  my.insert(9);

  my.erase(my_it);
  size_t count_before = my.count(9);
  size_t count_after = my.count(9);

//  cout << "count " << b.count(50) << endl;
  cout << "empty " << b.empty() << endl;

  return 0;
}