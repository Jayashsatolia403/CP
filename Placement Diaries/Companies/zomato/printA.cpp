//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


#define ll long long int

class Solution{
public:
    vector<ll> dp;
    
    ll dfs(int n, ll result, ll buffer, int cur) {
        if (cur == n) return result;
        else if (cur > n) {
            result /= 2;
            cur -= 3;
            result += max((ll)(n-cur), buffer*(n-cur));
            return result;
        }
        
        if (dp[cur] != -1) return dp[cur];
        
        return dp[cur] = max(dfs(n, result+buffer, buffer, cur+1),dfs(n, result*2, result, cur+3));
    }
    
    
    long long int optimalKeys(int n){
        if (n <= 5) return n;
        
        dp = vector<ll>(100, -1);
        
        ll result = dfs(n, 1, 0, 0);

        for (int i=0; i <= n; i++) cout << dp[i] << endl;
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<"Result : " << ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends