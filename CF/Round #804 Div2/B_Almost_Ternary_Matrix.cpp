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
        cin >> n >> m;
        int x= n, y = m;

        int a = 1, b = m-2;

        vector<VI> v(n, VI(m, 0));

        int i = 0;

        bool done = false;

        while (i < n) {
            
            rep (j, a, b+1) {
                v[i][j] = 1;
                if (n-i > 2) v[n-i-1][j] = 1;
            }

            rep (j, a, n-a) {
                v[j][a-1] = 1;
                v[j][b+1] = 1;
            }

            i+=2;
            n-=2;
            a++;
            b--;
        }

        rep (i, 0, x) {
            rep (j, 0, y) cout << v[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}