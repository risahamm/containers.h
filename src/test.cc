#include "iostream"
#include <vector>

using namespace std;

void rec()
{
    char a=0;
    cin >> a;
    if ( a == 'f' ) return;
    rec();
    cout << a << " ";

}

template <class T>
void summ (T a, T b) {
    cout <<  a + b << '\n';
}



int main()
{
//    rec();

    return 0;
}