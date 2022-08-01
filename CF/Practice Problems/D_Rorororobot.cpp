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


bool dfs(int x, int y, int k, int x2, int y2, int n, int m, vector<vector<int>>& v) {
    if (x < 0 || x >= n || y < 0 || y >= m || !v[x][y]) return false;

    if (x == x2 && y == y2) return true;

    return dfs(x-k, y, k, x2, y2, n, m, v) 
            || dfs(x+k, y, k, x2, y2, n, m, v) 
            || dfs(x, y-k, k, x2, y2, n, m, v) 
            || dfs(x, y+k, k, x2, y2, n, m, v);
};




int main() {
    cin >> n >> m;
    vector<VI> v(n, VI(m, 1));

    rep(i,0,m) {
        int x;
        cin >> x;

        per(j,n-x-1,n) {
            v[j][i] = 0;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        cout << dfs(x1, y1, k, x2, y2, n, m, v) << endl;
        // cout << (dfs(x1, y1, k) ? "YES" : "NO") << endl;
    }
    
    return 0;
}