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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;



const int N=201000;
int n,m,_;
    


int main() {
    ll t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v(n);
        rep (i, 0, n) cin >> v[i];

        vector<ll> prefixes(n), suffixes(n);

        rep (i,1,n-1) {
            if (i-2 >= 0) prefixes[i] += prefixes[i-2];
            prefixes[i] += max(0ll, max(v[i-1], v[i+1]) -v[i]+1);
        }

        per (i,1,n-1) {
            if (i+2 < n) suffixes[i] += suffixes[i+2];
            suffixes[i] += max(0ll, max(v[i-1], v[i+1]) -v[i]+1);
        } 

        ll ans = min(prefixes[n-2], suffixes[1]);

        if (n%2) {
            cout << ans<< endl;
            continue;
        }

        rep (i, 1, n-4) {
            ll cur = prefixes[i] + suffixes[i+3];
            ans = min(ans, cur);
            i++;
        }

        cout << ans << endl;
    }


    return 0;
}