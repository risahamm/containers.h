#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
#include "s21_tree.h"

using namespace std;

//typedef struct {
//  int x = 0;
//  int y = 0;
//} st;


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
  b.insert(6, 4);
  b.printTree();
  cout << "size = " << b.size() << endl;

//  st *a;
//  a->x = 4;
//  a->y = 9;
//  st *b;
//  b = a;
//  b->y = 12;
//  cout << "x = " << b->y << endl;
//  cout << "x2 = " << a->y << endl;




  return 0;
}