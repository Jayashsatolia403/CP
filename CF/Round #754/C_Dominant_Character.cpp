#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)


int result = 99999;



bool string_check(string s, int idx1, int idx2) {
    
    vector<int> arr = {0, 0, 0};


    for (int i = idx1; i < idx2+1; i++) {
        arr[s[i]-'a']++;
    }


    if ((arr[0] > arr[1]) && (arr[0] > arr[2]) && (arr[0] >= 2)) {
        return true;
    }

    return false; 
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, result=99999;
        string s;

        cin >> n >> s;

        forn (i, n) {
            vector<int> v(3, 0);

            v[s[i] - 'a']++;

            for (int j = i+1; j < min(n, i+7); j++) {
                v[s[j] - 'a']++;

                if (v[0] > v[1] && v[0] > v[2]) {
                    result = min(result, j-i+1);
                }
            }
        }
        
        
        cout << (result == 99999 ? -1 : result) << endl;
        

        // vector<int> arr = {0, 0, 0};
        // vector<int> a_indexes;


        // cin >> n;
        // cin >> s;

        // forn (f, n) {
        //     if (s[f] == 'a') {
        //         a_indexes.push_back(f);
        //     }
        // }


        // result = 99999;

        // if (a_indexes.size() < 2) {
        //     cout << -1 << endl;
        //     continue;
        // }

        // forn (i, a_indexes.size()-1) {
            
        //     int idx1 = a_indexes[i];
        //     int idx2 = a_indexes[i+1];


        //     if (string_check(s, idx1, idx2)) {
        //         result = min(result, idx2 - idx1 + 1);
        //     }
        // }


        // if (result == 99999) cout << -1 << endl;
        // else cout << result << endl;
    }

    return 0;
}