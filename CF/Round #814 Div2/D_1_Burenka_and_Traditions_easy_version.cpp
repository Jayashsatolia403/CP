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
    

int dp[5005][1<<13];

int dfs(VI &v, int idx, int cur) {
    if (idx == 0) {
        if (cur == 0) return 0;
        return 1;
    }

    if (dp[idx][cur] != -1) return dp[idx][cur];

    if (cur == 0) {
        return dp[idx][cur] = dfs(v, idx-1, v[idx-1]);
    }

    return dp[idx][cur] = 1 + min(dfs(v, idx-1, v[idx-1]), dfs(v, idx-1, v[idx-1]^cur));
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI v(n);
        rep (i, 0, n) cin >> v[i];
        
        rep (i, 0, n) rep (j, 0, 1<<13) dp[i][j] = -1;

        cout << dfs(v, n-1, v[n-1]) << endl;
    }
    
    return 0;
}