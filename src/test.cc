#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
//#include "s21_tree.h"

using namespace std;

int main() {

//  map<int, int> a;
//
//      a.insert({5, 1});
//      a.insert({3, 3});
//      a.insert({2, 7});
//      a.insert({4, 7});
//      a.insert({1, 7});
//      a.insert({6, 7});
//      a.insert({7, 7});
//      a.insert({8, 7});

//      cout << "insert->first " << a.insert({8, 0}).first->first << endl;
//      cout << "insert->second " << a.insert({8, 0}).second << endl;
//a.at(2) = 8;
//cout << a.at(2) << endl;

  s21::Tree<int, int> b;

//  for(int x = 0; x < 20; ++x) {
//    b.insert(x, 0);
//  }

  b.insert(40, 0);
  b.insert(20, 0);
//  b.insert(80, 0);
//  b.insert(10, 0);
//  b.insert(90, 0);
//  b.insert(5, 0);
//  b.insert(60, 0);
//  b.insert(70, 0);
//  b.insert(50, 0);
//  b.insert(45, 3);

  s21::Tree<int, int>::TreeIterator it = b.begin();
  cout << "it " << it->key << endl;

//  b.erase(b.end());

//  cout << "insert->first " << *b.insert_or_assign(45, 0).first << endl;
//  cout << "insert->second " << b.insert_or_assign(43, 56).first->data << endl;
//  cout << "insert->second " << b.insert(45, 56).second << endl;

//  b.at(45 ) = 5;

//  cout << "at " << b.contains(43) << endl;

//  cout << "max " << b.max_size() << endl;

  return 0;
}