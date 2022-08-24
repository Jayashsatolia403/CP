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

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}


const int N=201000;
ll n,m,_;
    
    
int main() {
    cin >> n >> m;
    vector<ll> v(n);
    rep (i,0,n) cin >> v[i];

    ll result = n*(n+1)/2;

    rep (i, 1, n+1) {
        if(v[i] != v[i-1]) result += i*(n-i);
    }

    rep (_, 0, m) {
        ll i, x;
        cin >> i >> x;
        i--;

        if (v[i]== x) {
            cout << result << endl;
            continue; 
        }

        if (i > 0 && v[i-1] != v[i]) result -= i*(n-i);
        if (i < n-1 && v[i+1] != v[i]) result -= (i+1)*(n-i-1);

        v[i] = x;

        if (i > 0 && v[i-1] != x) result += i*(n-i);
        if (i < n-1 && v[i+1] != x) result += (i+1)*(n-i-1);


        cout << result << endl;
    }
    
    return 0;
}