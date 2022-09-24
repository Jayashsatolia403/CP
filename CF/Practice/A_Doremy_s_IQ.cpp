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
    
vector<VI> dp;

int dfs(VI v, int idx, int iq, int score) {
    int n = v.size();
    if (idx >= n || iq <= 0) return score;

    // if (dp[idx][iq] != -1) return dp[idx][iq];

    int count = 0;

    while (idx < n && iq >= v[idx]) {
        idx++;
        count++;
    }

    score += count;

    if (idx == n) return score;

    return max(dfs(v, idx+1, iq-1, score+1), dfs(v, idx+1, iq, score));
}



int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int iq;
        cin >> n >> iq;
        VI v(n);
        rep (i, 0, n) cin >> v[i];

        // dp = vector<VI>(n, VI(10000, -1));

        cout << dfs(v, 0, iq, 0) << endl;
    }
    
    return 0;
}