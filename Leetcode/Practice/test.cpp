#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        map<long long, int> track;
        
        long long count = 0;
        
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == 0) count++;
            else if (count != 0) {
                track[count]++;
                count = 0;
            }
        }

        if (count != 0) track[count]++;
        
        long long result = 0;
        
        for (auto& it: track) {
            count = it.first*(it.first+1)/2;
            result += count * it.second;
        }
        
        return result;
    }
};


int main() {
    vector<int> nums = {0,0,0,2,0,0};
    cout << Solution().zeroFilledSubarray(nums) << endl;
    return 0;
}