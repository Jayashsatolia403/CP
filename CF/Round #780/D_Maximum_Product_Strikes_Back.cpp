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
    

pair<pair<ll,ll>,ll> get_max(VI v) {
    ll res = 0, count_negs=0, cur=1;

    for (ll i: v) if (i < 0) count_negs++;

    pair<ll,ll> good;


    if (count_negs % 2 == 0) {
        for (ll i: v) cur *= i;
        return {{0, 0}, cur};
    } else {
        ll before_neg = 1, after_neg = 1;
        bool done = false;

        ll cnt = 1;

        for (ll i: v) {
            if (i < 0 && !done) { done = true; continue; }

            if (!done) {
                before_neg *= i;
                cnt++;
            } else {
                after_neg *= i;
            }
        }

        if (before_neg > res) {
            res = before_neg;
            good = {0, SZ(v)-cnt+1};
        }
        if (after_neg > res) {
            res = after_neg;
            good = {cnt, 0};
        }

        before_neg = 1;
        after_neg = 1;
        done = false;
        cnt = 1;

        reverse(all(v));

        for (ll i: v) {
            if (i < 0 && !done) { done = true; continue; }

            if (!done) {
                before_neg *= i;
                cnt++;
            } else {
                after_neg *= i;
            }
        }

        if (before_neg > res) {
            res = before_neg;
            good = {SZ(v)-cnt, 0};
        }
        if (after_neg > res) {
            res = after_neg;
            good = {0, cnt};
        }
    }

    return {good, res};
}


int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI v(n, 0);
        rep (i, 0, n) {
            cin >> v[i];
        }

        ll result = 0, last = 0;

        VI zero_eliminated;
        pair<ll,ll> good;

        rep (i, 0, n) {
            if (v[i] == 0) {
                pair<pair<ll,ll>, ll> cur = get_max(zero_eliminated);

                if (cur.se > result) {
                    result = cur.se;
                    good = cur.fi;

                    good.fi += last;
                    good.se += n-i;
                }
                last = i+1;
                zero_eliminated = VI();
            } else {
                zero_eliminated.pb(v[i]);
            }
        }

        pair<pair<ll,ll>, ll> cur = get_max(zero_eliminated);

        if (cur.se > result) {
            result = cur.se;
            good = cur.fi;

            good.fi += last;
        }

        cout << good.fi << " " << good.se << endl;
    }
    
    return 0;
}