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
    cin >> n;
    
    ll a=0, b=0;
    
    vector<ll> v1(n, 0);
    vector<ll> v2(n-1, 0);
    vector<ll> v3(n-2, 0);
    
    rep (i, 0, n) cin >> v1[i];
    rep (i, 0, n-1) cin >> v2[i];
    rep (i, 0, n-2) cin >> v3[i];
    
    sort(all(v1));
    sort(all(v2));
    sort(all(v3));
    
    rep (i, 0, n) {
        if (i < n-1 && v1[i] != v2[i]) {cout << v1[i] << endl; break;}
        else if (i==n-1) cout << v1[i] << endl;
    }
    
    rep (i, 0, n-1) {
        if (i < n-2 && v2[i] != v3[i]) {cout << v2[i] << endl; break;}
        else if (i==n-2) cout << v2[i] << endl;
    }
    
    
    return 0;
}