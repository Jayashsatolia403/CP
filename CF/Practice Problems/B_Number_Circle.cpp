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
    vector<ll> v(n, 0);

    rep (i, 0, n) cin >> v[i];

    sort(all(v));

    bool correct = true;

    if(v[n-1]>=v[n-2]+v[n-3]) correct = false;
    

    cout << (correct ? "YES" : "NO") << endl;

    
    if (correct) {
        cout << v[n-2] << " ";
        rep (i, 0, n-2) cout << v[i] << " ";
        cout << v[n-1];
    }
    

    return 0;
}


// Logic : Sort the array. then we can observe that numbers in the middle will always be less than their neighbors. so we just check 
//         if last number is greater than n-1 + n-2 th then we can say arrange them in such a way that nth number stays in middle of 
//         n-1 and n-2 or else print NO.