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
    int n, q;
    cin >> n >> q;

    int v[n][n];

    rep (i, 0, n) {
        rep (j, 0, n) {
            v[i][j] = false;
        }
    }

    rep (_, 0, q) {
        int t, x, y, x1, x2, y1, y2;
        cin >> t;

        if (t == 1) {
            cin >> x >> y;
            v[x-1][y-1] = 1;
        }
        else if (t == 2) {
            cin >> x >> y;
            v[x-1][y-1] = 0;
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;

            bool final = true; 

            int xs[n], ys[n];

            rep (x, x1-1, x2) {
                bool done = false;

                rep (i, 0, n) {
                    if (v[x][i]) done = true;
                }

                xs[x] = done;
            }

            rep (y, y1-1, y2) {
                bool done = false;

                rep (i, 0, n) {
                    if (v[i][y]) done = true;
                }

                ys[y] = done;
            }

            rep (x, x1-1, x2) {
                rep (y, y1-1, y2) {
                    if (!xs[x] && !ys[y]) final = false;
                }
            }

            cout << (final ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}