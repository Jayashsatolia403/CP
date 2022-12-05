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



int dfs(VI &v, int idx, map<pair<int,int>,int> dp, int sum, int count) {
    if (idx == v.size() || count > (v.size()-1)/2) {
        return sum;
    }

    if (dp.find({idx, sum}) != dp.end()) {
        return dp[{idx, sum}];
    }

    int ans = 0;
    if (dfs(v, idx + 1, dp, sum + v[idx], count+1) || dfs(v, idx + 1, dp, sum, count));

    return dp[{idx,sum}] = ans;
}


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI v(n);
        rep (i, 0, n) cin >> v[i];

        cout << (dfs(v, 0, {}, 0, 0)%2?"Bob":"Alice") << endl;
    }
    
    return 0;
}