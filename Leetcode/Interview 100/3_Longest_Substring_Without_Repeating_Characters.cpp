#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> hashset;

        int n = s.length();

        int result = 0, count = 0, left = 0;

        for (int right=0; right < n; right++) {
            char c = s[right];

            if (hashset.count(c)) {
                while (hashset.count(c)) {
                    hashset.erase(s[left++]);
                    count--;
                }
            }
            
            hashset.insert(c);

            count++;

            result = max(result, count);
        }

        return result;
    }
};


int main() {
    string s;
    cin >> s;

    cout << Solution().lengthOfLongestSubstring(s) << endl;
}