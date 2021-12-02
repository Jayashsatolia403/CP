#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


void print_array(vector<int> arr) {
    int n = arr.size();

    cout << "[ ";

    forn (i, n) {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}