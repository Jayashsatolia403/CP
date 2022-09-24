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
        cin >> n;
        VI v(n);
        rep (i,0,n) cin >> v[i];

        rep (i,1,n) {
            v[i] += v[i-1];
        }

        cin >> m;

        rep (i, 0, m) {
            int k, x, y;
            cin >> k >> y >> x;

            set<int> f;
            int prev = 0;
            rep (j, 0, n-k+1) {
                f.insert(v[j+k-1] - prev);
                prev = v[j];
            }

            for (int i : f) cout << i << " ";
            cout << endl;

            per(j, 0, 32) {
                int count = 0;

                for (int i : f) {
                    if (i & (1<<j)) {
                        count++;
                    }
                }

                if (count >= y) {
                    for (int i : f) {
                        if (i & (1<<j) == 0) {
                            f.erase(i);
                        }
                    }
                }
            }

            int result = INT_MAX;
            for (int i : f) {
                result &= i;
            }

            cout << (result | x) << endl;

        }
    }
    
    return 0;
}