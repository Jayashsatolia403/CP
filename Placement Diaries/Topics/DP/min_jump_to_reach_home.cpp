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
    
    int recur(set<int> &s, int cur, int a, int b, int x, bool prev) {
        if (s.find(cur) != s.end()) {
            return 1e8;
        }
        if (cur > 6000 || cur < 0) return 1e8;
        if (cur == x) return 0;

        if (dp[cur][prev] != -1) return dp[cur][prev];

        int result = 0;

        
        
        if (prev) {
            int forward = recur(s, cur+a, a, b, x, prev);
            result = 1 + forward;
        }
        else {
            int forward = recur(s, cur+a, a, b, x, prev);
            int backward = recur(s, cur-b, a, b, x, !prev);
            result = 1+min(forward, backward);
        }

        dp[cur][prev] = result;

        return result;
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        set<int> s;
        for (int i : forbidden) s.insert(i);

        int N = 6001;

        dp = vector<vector<int>>(N, vector<int>(2, -1));

        int result = recur(s, 0, a, b, x, 0);

        return result>=1e8?-1:result;
    }
};


int main() {
    int n, a, b, x;
    cin >> n >> a >> b >> x;
    VI forbidden(n);
    rep (i, 0, n) cin >> forbidden[i];

    cout << Solution().minimumJumps(forbidden, a, b, x) << endl;
    
    return 0;
}