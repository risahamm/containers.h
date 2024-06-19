#include <iostream>
#include <map>
#include <vector>

#include "s21_containers.h"
#include "s21_tree.h"

using namespace std;


int main() {

//  map<int, int> a;
////  const auto [it_hinata, success] =
//      a.insert({1, 5});
//      a.insert({1, 3});
//      a.insert({1, 7});
//  cout << a.at(1) << endl;


  s21::Tree<int, int> b;
  b.insert(1, 2);
  b.printTree();
  cout << "size = " << b.size() << endl;

  return 0;
}