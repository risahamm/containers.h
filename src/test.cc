#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
//#include "s21_tree.h"

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
//a.at(2) = 8;
//cout << a.at(2) << endl;

  s21::Tree<int, int> b;
  s21::Tree<int, int> c;

//  for(int x = 0; x < 20; ++x) {
//    b.insert(x, 0);
//  }

  b.insert(6, 0);
  b.insert(3, 0);
  b.insert(9, 0);
  b.insert(1, 0);
  b.insert(4, 0);

  auto it = c.insert(5, 0);
  c.insert(7, 0);
  c.insert(8, 0);
  c.insert(6, 0);
//  b.insert(50, 0);
//  b.insert(45, 3);

//  c.erase(it.first);

  b.merge(c);

//  s21::Tree<int, int>::TreeIterator it = b.begin();
//  cout << "it " << it->key << endl;

//  b.erase(b.end());

//  cout << "insert->first " << *b.insert_or_assign(45, 0).first << endl;
//  cout << "insert->second " << b.insert_or_assign(43, 56).first->data << endl;
//  cout << "insert->second " << b.insert(45, 56).second << endl;

//  b.at(45 ) = 5;

//  b.clear();

//  cout << "at " << b.contains(43) << endl;

  cout << "empty " << b.empty() << endl;

  return 0;
}