#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
// #include "s21_tree.h"

using namespace std;

int main() {
//    map<int, int> a;
//    map<int, int> b;
//  //
//    a.insert({5, 1});
//    a.insert({3, 3});
//    a.insert({2, 7});
//
//    b.insert({1, 1});
//    b.insert({4, 3});
//    b.insert({6, 7});
//
//    a.merge(b);

  //      cout << "insert->first " << a.insert({8, 0}).first->first << endl;
  //      cout << "insert->second " << a.insert({8, 0}).second << endl;
  // a.at(2) = 8;
  // cout << a.at(2) << endl;

  s21::Map<int, int> my;
//  auto it = my.insert(40, 0);
//  my.insert(10, 1);
//  my.insert(20, 2);
//  my.insert(15, 3);
//  my.insert(90, 4);
//  my.insert(5, 5);
//  my.insert(60, 6);
//  auto it2 = my.insert(70, 7);
//  my.insert(50, 8);
//  my.insert(45, 9);

  my.insert_many(pair<int, int>(1, 1), pair<int, int>(2, 2), pair<int, int>(3, 3));


//
//  s21::Map<int, int> b;
//  b = std::move(a);

//  cout << "a = " << a.size() << endl << "b = " << b.size() << endl;
//  cout << "empty " << my.empty() << endl;

  return 0;
}