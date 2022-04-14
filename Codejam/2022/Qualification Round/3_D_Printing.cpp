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
    
    rep(_ ,0,t) {
        vector<VI> v(3, VI(4, 0));

        rep (x,0,3) {
            rep (i,0,4) {
                cin >> v[x][i];
            }
        }

        VI mins(4, INT_MAX);

        rep (i,0,4) {
            rep (j,0,3) {
                mins[i] = min(mins[i], v[j][i]);
            }
        }

        int total = 0;
        rep (i, 0, 4) total += mins[i];

        if (total < pow(10, 6)) {
            cout << "Case #" << _+1 << ": " << "IMPOSSIBLE" << endl;
        }
        else {
            int diff = total - pow(10, 6);

            // sort(all(mins));

            per (i, 0, 4) {
                if (mins[i] >= diff) {
                    mins[i] -= diff;
                    break;
                }
                else {
                    diff -= mins[i];
                    mins[i] = 0;
                }
            }

            cout << "Case #" << _+1 << ": ";

            rep (i, 0, 4) cout << mins[i] << " ";
            cout << endl;
        }
    }
    
    return 0;
}