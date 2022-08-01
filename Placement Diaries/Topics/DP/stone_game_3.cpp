#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
    
const int N=201000;
int n,m,_;



class Solution {
public:
    
    int dfs(vector<int> &v, int idx, vector<int>& dp) {
        
        int n = v.size();
        if (idx >= n) return 0;

        if (dp[idx] != INT_MIN) return dp[idx];

        int total = 0;
        
        for (int i=idx; i < n; i++) total += v[i];

        int my_score = INT_MIN+10000;

        for (int i=idx; i<idx+3; i++) {
            int opp_score = dfs(v, i+1, dp);

            my_score = max(my_score, total-opp_score);
        }

        dp[idx] = my_score;

        return my_score;
    }


    string dp_iterative(vector<int> &v) {
        int n = v.size();

        vector<int> dp(n, -1e8);

        for (int i=n-1; i >= 0; i--) {
            int sum = 0;

            for (int j=i; j < min(i+3, n); j++) {
                sum += v[j];

                int opp_score = j+1 < n ? dp[j+1] : 0;

                dp[i] = max(dp[i], sum-opp_score);
            }
        }

        return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob";
    }


    string stoneGameIII(vector<int>& stoneValue) {

        return dp_iterative(stoneValue);
        
        vector<int> dp(stoneValue.size(), INT_MIN);

        int result = dfs(stoneValue, 0, dp);

        int total = 0;
        for (int i : stoneValue) total += i;

        // cout << result << endl;

        if (result == total-result) return "Tie";

        return (result > total-result ? "Alice" : "Bob");
    }
};



    
int main() {
    
    int n;
    cin >> n;
    vector<int> stoneValue(n);
    for (int i=0; i < n; i++) cin >> stoneValue[i];

    cout << Solution().stoneGameIII(stoneValue);
    
    return 0;
}