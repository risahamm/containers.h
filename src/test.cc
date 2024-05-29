#include <iostream>
#include <vector>

#include "s21_containers.h"

using namespace std;

int main() {
    vector<int> f;
    f.push_back(1);
    f.push_back(2);
    f.push_back(3);

    cout << "size " << f.size() << endl;
    cout << "capacity " << f.capacity() << endl << endl;

    for(int i = 0; i < f.size(); i++) {
      cout << f[i] << endl;
    }

    f.erase(f.end());

    cout << "size " << f.size() << endl;
    cout << "capacity " << f.capacity() << endl << endl;

    for(int i = 0; i < f.size(); i++) {
      cout << f[i] << endl;
    }

//  s21::Vector<int> a(5);
//  a[0] = 11;
//  a[1] = 22;
//  a[2] = 33;
//  a[3] = 44;
//  a[4] = 55;
//
//  for ( int i = 0; i < a.size(); i++) {
//    cout << a[i] << endl;
//  }
//  cout << "___________________" << endl;
//
//  a.erase(a.begin());
//
//  cout << "size = " << a.size() << endl;
//
//  for ( int i = 0; i < a.size(); i++) {
//    cout << a[i] << endl;
//  }

  return 0;
}