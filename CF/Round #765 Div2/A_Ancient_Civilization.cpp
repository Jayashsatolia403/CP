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
        cin >> n >> m;

        ll ans=0;

        vector<ll> v(n, 0);
        rep (i,0,n) cin >> v[i];

        rep (i, 0, 30) {
            int cnt1=0, cnt2=0;

            rep (j, 0, n) {
                if (v[j] & (1 << i)) cnt1++;
                else cnt2++;
            }

            if (cnt1 > cnt2) ans+=(1 << i);
        }

        cout << ans << endl;
    }

    return 0;
}

// Simplifying Question : We are given n numbers and we need to find out a number y whose sum of distances from all numbers of vector is
//                        minimum.

// Observations : 1. We have to deal with binary form.
//                2. y is less than 2**30-1 means length of binary representation string of number y is less than 30.
//                3. So we can iterate from 0..29 and check if more bits are set or unset.
//                4. If set bits are more than unset bits that indicated that we have 