#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
//#include "s21_tree.h"

using namespace std;

int main() {

//  map<int, int> a;
////  const auto [it_hinata, success] =
//      a.insert({1, 5});
//      a.insert({1, 3});
//      a.insert({1, 7});
//  cout << a.at(1) << endl;


  s21::Tree<int, int> b;
  b.insert(4, 2);
  b.insert(2, 4);
  b.insert(2, 7);
  b.insert(6, 4);
  b.insert(1, 4);
  b.insert(6, 3);
  cout << "find " << b.find(2) << endl;
  cout << "size = " << b.size() << endl;

//  int x = 5;
//  int *p = &x;
//  int **pp = &p;
//  *(*pp) = 8;
//
//  cout << "x = " << x << endl;





  return 0;
}