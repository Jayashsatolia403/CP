#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


void print_vector(vector<int> arr) {
    int n = arr.size();

    cout << "[ ";

    forn (i, n) {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}

void print_set(set<int> hashset) {

    cout << "{ ";

    for (int it : hashset) {
        cout << it << " ";
    }

    cout << "}" << endl;
}

void print_map(map<int, vector<int>> hashmap) {
    cout << "{ ";

    for (pair<int, vector<int>> k : hashmap) {
        cout << k.first << "=";
        print_vector(k.second);
        cout << ", ";
    }

    cout << "}" << endl;
}