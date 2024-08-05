#include <iostream>
#include <set>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
  //  multiset<int> a;
  //
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
  b.insert(60);
  b.insert(40);
  b.insert(70);
  b.insert(30);
  b.insert(65);
  b.insert(50);
  b.insert(80);
  b.insert(50);
  b.insert(50);
  b.insert(50);
  //  b.insert(70);
  //  b.insert(50);
  //  b.insert(45);

  //  auto p2 = b.equal_range(80);
  //
  //  cout << "p2 " << *p2.first << endl;
  //  cout << "p2 " << *p2.second << endl;

  cout << "count " << b.count(50) << endl;
  cout << "empty " << b.empty() << endl;

  return 0;
}