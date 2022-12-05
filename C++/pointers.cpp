#include <bits/stdc++.h>
using namespace std;


int main() {
    int x = 2;

    int *y;

    y = &x;

    *y = 4;

    cout << &x << endl;
    cout << y << endl;

    cout << &x << endl;
    cout << y << endl;


    return 0;
}