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


int main() {
    int t;
    cin >> t;

    while (t--) {

        cin >> n >> m;

        ll backup = n/2;

        if (m == 0) {
            rep (i, 0, n/2) {
                cout << i << " " << n-i-1 << endl;
            }

            continue;
        }

        bool isBad = false;

        for (int i=0; i < n; i+=4) {
            m -= i*2;

            if (m < 0) { isBad=true; break; }
        }

        int diff = backup - m;

        if (diff < 0 || isBad) {cout << -1 << endl; continue; }

        for (int i=0; i < n; i+=4) {
            if (diff == backup) {
                cout << i << " " << i+3 << endl;
                cout << i+1 << " " << i+2 << endl;
            }
            else if (diff+1 == backup) {
                cout << i << " " << i+2 << endl;
                cout << i+1 << " " << i+3 << endl;
                diff++;
            }
            else {
                cout << i << " " << i+1 << endl;
                cout << i+2 << " " << i+3 << endl;
                diff += 2;
            }
        }
    }

    return 0;
}