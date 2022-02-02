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

int get_area(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) * abs(y1 - y2);
}

int main() {
    cin >> n;

    if (n <= 1) { cout << -1 << endl; return 0; }

    vector<PII> v;

    rep (i, 0, n) {
        int x, y;
        cin >> x >> y;

        v.pb({x, y});
    }

    if (n == 2) {
        if (v[0].fi == v[1].fi || v[0].se == v[1].fi) {
            cout << -1 << endl;
            return 0;
        } else {
            
            cout << get_area(v[0].fi, v[0].se, v[1].fi, v[1].se) << endl;

            return 0;
        } 
    }

    set<int> xs, ys;

    rep (i, 0, n) {
        xs.insert(v[i].fi);
        ys.insert(v[i].se);
    }

    cout << get_area(*xs.begin(), *ys.begin(), *xs.rbegin(), *ys.rbegin()) << endl;

    return 0;
}