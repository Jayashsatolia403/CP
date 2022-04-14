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
ll n,m,_;



bool is_interesting(int a) {
    ll sum_digits = 0;
    ll product = 1;

    while (a) {
        product *= a%10;
        sum_digits += a%10;
        a /= 10;
    }

    return (product%sum_digits==0);

}
    
    
int main() {
    int t;
    cin >> t;
    
    rep (T, 1, t+1) {
        cin >> n >> m;

        ll result = 0;

        for (ll i=n; i <=m; i++) {
            if (is_interesting(i)) {
                result++;
                // cout << i << endl;
            }
        }

        cout << "Case #" << T << ": " << result << endl;
    }
    
    return 0;
}