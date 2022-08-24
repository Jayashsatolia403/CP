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
    


// if we are using some color to fill in the middle then it must be able to fill >= 2 columns or rows.
// no of colors available should be >= n*m
// we can make 2 functions where one will check if we can fill vertically same and second will check if we can fill horizontally same
// in the case of vertical fill if m is odd then we need one club of 3 columns and remaining must be in club of 2s.
// same logic in horizontal fill





int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> v(k);
        rep(i,0,k) cin >> v[i];
        sort(all(v));

        bool good = false;

        for (ll _=0; _<2; _++) {
            ll count3 = m%2, count2 = m/2;

            for (ll i : v) {
                ll x = i;

                if (n*3 <= x && count3) {
                    count3--;
                }
                
                if (n*2 <= x && count2) {
                    count2 -= x/(n*2);
                }
            }

            if (count3 == 0 && count2 <= 0) {
                good = true;
                break;
            }
            swap(n, m);
        }

        cout << (good?"Yes":"No") << endl;
    }
    
    return 0;
}