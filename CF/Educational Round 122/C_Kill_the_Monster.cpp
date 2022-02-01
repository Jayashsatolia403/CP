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

bool check(ll hc, ll dc, ll hm, ll dm) {
    return (hc-1)/dm >= (hm-1)/dc;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        ll hc, dc, hm, dm, k, w, a;

        cin >> hc >> dc >> hm >> dm >> k >> w >> a;

        bool done = false;

        rep (i, 0, k+1) {
            if (check(hc+(a*i), dc+w*(k-i), hm, dm)) {done = true; break;}
        }

        if (!done) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}