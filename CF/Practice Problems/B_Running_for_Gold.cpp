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
        VI good_ranks(5, 0);


        int n;
        cin >> n;
        
        vector<vector<int>> v(5, vector<int>(n, 0));
        VI x(n, 0);

        rep (i, 0, n) {
            rep (j, 0, 5) cin >> v[j][i];
        }

        rep (i, 0, 5) {
            int a = *min_element(all(v[i]));

            good_ranks[i] = a;
        }

        cout << good_ranks[0] << ", "  << good_ranks[1] << ", " << good_ranks[2] << ", " << good_ranks[3] << ", " << good_ranks[4] << ", " << endl;

        rep (i, 0, 5) {
            rep (j, 0, n) {
                if (v[i][j] == good_ranks[i]) {
                    x[j]++;
                }
            }
        }

        rep (i, 0, n) cout << x[i] << ", ";
        cout << endl;

        bool done = false;

        rep (i, 0, n) {
            if (x[i] >= 3) {
                done = true;
                cout << i+1 << endl;
                break;
            }
        }

        if (!done) cout << -1 << endl;
    }

    return 0;
}
