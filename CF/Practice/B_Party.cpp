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
        VI v(n);
        rep (i, 0, n) cin >> v[i];


        VI count(n+1, 0);

        map<int,vector<int>> g;

        rep (i, 0, m) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            count[a]++;
            count[b]++;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        int result = INT_MAX;

        if (m%2 == 0) {
            cout << 0 << endl;
            continue;
        }


        for (int i=0; i < n+1; i++) {
            if (count[i]%2 == 1) {
                result = min(result, v[i]);
            }
        }

        for (int i=0; i < n; i++) {
            if (g.find(i) != g.end()) {
                if (count[i]%2 == 0) {
                    for (int j : g[i]) {
                        if (count[j] % 2 == 0) result = min(result, v[i] + v[j]);
                    }
                }
            }
        }


        cout << result << endl;
    }
    
    return 0;
}