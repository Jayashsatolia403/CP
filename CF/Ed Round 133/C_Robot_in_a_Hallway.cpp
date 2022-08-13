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


vector<VI> vis;

int dfs(vector<VI> &v, int i, int j, int count, int cur) {
    cout << cur << endl;
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) return INT_MIN;
    if (count == n*m) return cur;

    if (v[i][j] > cur) cur += abs(v[i][j] - cur);
    else cur++;

    int x = INT_MAX;
    
    vis[i][j] = true;
    x = max(cur, dfs(v, i+1, j, count+1, cur));
    x = max(cur, dfs(v, i, j+1, count+1, cur));
    x = max(cur, dfs(v, i-1, j, count+1, cur));
    x = max(cur, dfs(v, i, j-1, count+1, cur));
    vis[i][j] = false;

    return cur+x;
}



int main() {
    int t;
    cin >> t;

    
    while (t--) {
        cin >> m;
        n = 2;
        vis = vector<VI>(n, VI(m, 0));
        vector<VI> v(n, VI(m, 0));
        rep(i,0,m) v[0][i] = i+1;
        rep(i,0,m) v[1][i] = i+1;

        int result =  dfs(v, 0, 0, 0, 0);

        cout << " > " << result << endl;

        break;
    }
    
    return 0;
}