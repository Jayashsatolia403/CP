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
    ll t;
    cin >> t;

    while (t--) {
        ll w, h;
        cin >> w >> h;

        ll k;
        cin >> k;

        ll f1, l1, f2, l2, f3, l3, f4, l4, useless;

        rep (i, 0, k) {
            if (i==0) cin >> f1;
            else if (i==k-1) cin >> l1;
            else cin >> useless;
        }

        cin >> k;

        rep (i, 0, k) {
            if (i==0) cin >> f2;
            else if (i==k-1) cin >> l2;
            else cin >> useless;
        }

        cin >> k;

        rep (i, 0, k) {
            if (i==0) cin >> f3;
            else if (i==k-1) cin >> l3;
            else cin >> useless;
        }

        cin >> k;

        rep (i, 0, k) {
            if (i==0) cin >> f4;
            else if (i==k-1) cin >> l4;
            else cin >> useless;
        }

        ll first = 0, second = 0;

        first = max(abs(l1-f1), abs(l2-f2)) * h;
        second = max(abs(l3-f3), abs(l4-f4)) * w;

        cout << max(first, second) << endl;
    }

    return 0;
}
