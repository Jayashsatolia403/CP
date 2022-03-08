#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        char c;
        cin >> c;

        int count = 0;
        vector<int> idxs;

        for (int i=0; i < s.length(); i++) if (s[i] == c) { count++; idxs.push_back(i); }

        bool result = false;

        if (s.length() == 1 && s[0] == c) {cout << "YES" << endl; continue;}

        if (s.length()%2 && count > 0) {
            if (count == 1) {
                int check = idxs[0]+1;
                if (check%2) result = true; 
            }
            else if (count == 2) {
                int a1 = idxs[0]+1;
                int a2 = idxs[1]+1;

                if (a1%2 == 1 || a2%2 == 1) result = true;
            }
            else result = true;
        }

        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}