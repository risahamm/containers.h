#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
// #include "s21_tree.h"

using namespace std;

int main() {
  //  map<int, int> a;
  //
  //  a.insert({5, 1});
  //  a.insert({3, 3});
  //  a.insert({2, 7});
  //  a.insert({4, 7});
  //  a.insert({1, 7});
  //  a.insert({6, 7});
  //  a.insert({7, 7});
  //  a.insert({8, 7});

  //      cout << "insert->first " << a.insert({8, 0}).first->first << endl;
  //      cout << "insert->second " << a.insert({8, 0}).second << endl;
  // a.at(2) = 8;
  // cout << a.at(2) << endl;

//  s21::Tree<int, int> b;
//
//  b.insert(6, 0);
//  b.insert(3, 0);
//  b.insert(9, 0);
//  b.insert(1, 0);
//  b.insert(4, 0);


  s21::Map<int, int> a;

  a.insert(6, 0);
  a.insert(3, 0);
  a.insert(9, 0);

  cout << "empty " << a.empty() << endl;

  return 0;
}