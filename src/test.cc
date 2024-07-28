#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
// #include "s21_tree.h"

using namespace std;

int main() {
    map<int, int> a;
    map<int, int> b;
  //
    a.insert({5, 1});
    a.insert({3, 3});
    a.insert({2, 7});

    b.insert({1, 1});
    b.insert({4, 3});
    b.insert({6, 7});

    a.merge(b);

  //      cout << "insert->first " << a.insert({8, 0}).first->first << endl;
  //      cout << "insert->second " << a.insert({8, 0}).second << endl;
  // a.at(2) = 8;
  // cout << a.at(2) << endl;

//  s21::Map<int, int> a;

//  a.insert(6, 0);
//  a.insert(3, 0);
//  a.insert(9, 0);
//  a.insert(1, 0);
//  a.insert(4, 0);
//
//  s21::Map<int, int> b;
//  b = std::move(a);

//  cout << "a = " << a.size() << endl << "b = " << b.size() << endl;
//  cout << "empty " << a.empty() << endl;

  return 0;
}