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
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<ll> v(n, 0);

        rep (i, 0, n) cin >> v[i];

        ll small_odds=0, big_odds=0, evens=0;

        rep (i, 1, n-1) {
            if (v[i] == 0) continue;
            else if (v[i] == 1) small_odds++;
            else if (v[i] & 1) big_odds++;
            else evens++;
        }

        ll ans = 0;

        rep (i, 1, n-1) {
            if (v[i] & 1) ans += v[i]+1;
            else ans += v[i];
        }

        if (evens == 0 && small_odds > 0 && big_odds == 0) cout << -1 << endl;
        else if (evens == 0 && small_odds == 0 && big_odds == 1) cout << -1 << endl;
        else cout << ans/2 << endl;

        // if (evens == 0 && ((small_odds > 0 && big_odds == 0) || (big_odds == 1 && small_odds == 0))) cout << -1 << endl;
        // else cout << ans/2 << endl;
    }
    
    return 0;
}