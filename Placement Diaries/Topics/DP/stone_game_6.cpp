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
    vector<vector<int>> dp;

    int dfs(vector<int> &v, int left, int right, bool turn) {
        if (left >= right) return 0;

        if (dp[left][right]) return dp[left][right];

        int total = 0;
        for (int i=left; i <= right; i++) total += v[i];

        int a = dfs(v, left+1, right, !turn);
        int b = dfs(v, left, right-1, !turn);


        if (turn) {
            a += total-v[left];
            b += total-v[right];
            dp[left][right] = max(a, b);
        }
        else {
            a -= (total-v[left]);
            b -= (total-v[right]);
            dp[left][right] = min(a, b);
        }

        return dp[left][right];
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        dp = vector<vector<int>>(n, vector<int>(n, 0));

        int result = dfs(stones, 0, n-1, 1);

        return result;
    }
};




int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI v(n);
        rep (i, 0, n) cin >> v[i];

        cout << Solution().stoneGameVII(v) << endl;
    }
    
    return 0;
}