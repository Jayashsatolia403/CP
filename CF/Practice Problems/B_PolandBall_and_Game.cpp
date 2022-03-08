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
    cin >> n >> m;
    vector<string> p(n, ""), q(m, "");
    
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, m) cin >> q[i];

    set<string> commons, set_q;

    rep (i, 0, m) set_q.insert(q[i]);

    rep (i, 0, n) if (set_q.count(p[i])) commons.insert(p[i]);

    n += commons.size()%2;


    cout << (n > m ? "YES" : "NO") << endl;

    return 0;
}