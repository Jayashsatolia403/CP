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
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
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
    cin >> n;

    int last = 0;
    bool done = false;

    int res = 0, mx=0, mn = INT_MIN;

    rep (i, 0, n) {
        cin >> m;

        if (res==0) mn = m;

        if (mn < m && done) {
            cout << -1;
            return 0;
        } 

        if (m < last) {
            if (!done) {
                done = true;

                if (mn < m && done) {
                    cout << -1;
                    return 0;
                } 
            }

            else {
                cout << -1;
                return 0;
            }
        }

        last = m;

        if (!done) mx = max(mx, m);

        if (!done) res++;
    }

    // cout << res;

    if (res == n && !done) cout << 0;
    else cout << n-res;


    return 0;
}