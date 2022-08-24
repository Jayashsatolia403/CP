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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll val = k*b;

        if (val > s) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> result;
        s-=val;


        while (n--) {
            if (s > k-1) {
                s -= k-1;
                result.push_back(k-1+val);
                val = 0;
            }
            else {
                s = max(s, (ll)0);
                result.push_back(s+val);
                s = 0;
                val = 0;
            }
        }

        if (s) cout << -1 << endl;
        else {
            for (ll i : result) cout << i << " ";
            cout << endl;
        }
    }
    
    return 0;
}