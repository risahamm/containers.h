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
//
//      auto it = a.begin();
//      cout << "begin: " << it->first << endl;
//      a.erase(it);
//      cout << "a: " << a.at(1) << endl;



  s21::Tree<int, int> b;

//  for(int x = 0; x < 20; ++x) {
//    b.insert(x, 0);
//  }

//  b.insert(40, 0);
//  b.insert(20, 0);
//  b.insert(80, 0);
//  b.insert(10, 0);
//  b.insert(90, 0);
//  b.insert(5, 0);
//  b.insert(60, 0);
//  b.insert(70, 0);
//  b.insert(50, 0);
//  b.insert(45, 0);

  b.insert(80, 0);
  b.insert(60, 0);
  b.insert(90, 0);
  b.insert(50, 0);
  b.insert(70, 0);
  b.insert(45, 0);


  cout << "contains " << b.contains(6) << endl;
  cout << "size = " << b.size() << endl;

//  s21::Tree<int, int>::TreeIterator one = b.find(6);
//  cout << "iterator " << one->key << endl;


  return 0;
}