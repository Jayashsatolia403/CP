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
    ll t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) {
            cout  << "0 0" << endl;
            continue;
        }

        if (a==0) {
            cout << b << " " << 0 << endl;
            continue;
        }
        else if (b==0) {
            cout << a << " " << 0 << endl;
            continue;
        }

        ll diff = abs(a-b);

        ll f = ((a<b)?(a%diff):(b%diff));

        cout << diff << " " << ((f > diff-f)?(diff-f):f) << endl;
    }

    return 0;
}