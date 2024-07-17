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


  cout << "max " << b.max_size() << endl;

//  b.erase(b.find(70));

//  cout << "insert->first " << *b.insert(45, 0).first << endl;
  cout << "insert->second " << b.insert(45, 0).second << endl;


  return 0;
}