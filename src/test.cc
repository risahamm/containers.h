#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
//#include "s21_tree.h"

using namespace std;

int main() {

//  map<int, int> a;
////  const auto [it_hinata, success] =
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
//      cout << it->first << endl;
//      it++;
//      cout << it->first << endl;
//      it++;
//      cout << it->first << endl;
//      it++;
//      cout << it->first << endl;
//      it++;
//      cout << it->first << endl;


  s21::Tree<int, int> b;

  for(int x = 0; x < 500; ++x) {
    b.insert(x, 0);
  }



  cout << "contains " << b.contains(12) << endl;
  cout << "size = " << b.size() << endl;

  s21::Tree<int, int>::TreeIterator one = b.find(6);
  cout << "iterator " << *one << endl;

  return 0;
}