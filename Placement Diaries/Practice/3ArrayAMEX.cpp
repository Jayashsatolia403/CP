#include <bits/stdc++.h>
using namespace std;





int main() {
    int n;
    cin >> n;
    // Take 3 vector from input
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> v3(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    for(int i=0;i<n;i++){
        cin>>v3[i];
    }



    // Sort the vectors
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());

    vector<int> v2Ans(n);
    int prev = 0;

    for (int i=0; i < n; i++) {
        int idx = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();

        v2Ans[i] = idx+prev;
        prev = v2Ans[i];
    }


    int result = 0;

    for (int i=0; i < n; i++) {
        int idx = lower_bound(v2.begin(), v2.end(), v3[i]) - v2.begin();

        result += v2Ans[idx-1];
    }

    cout << result << endl;

    return 0;

}