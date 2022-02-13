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
    
    
int main() {
    cin >> n;
    VI v(n, 0);
    rep(i,0,n) cin >> v[i];

    VI dp(n, INT_MAX);

    dp[0] = 0;
    dp[1] = abs(v[0]-v[1]);

    rep (i, 2, n) {
        dp[i] = min(abs(v[i]-v[i-1])+dp[i-1], abs(v[i]-v[i-2])+dp[i-2]);
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}