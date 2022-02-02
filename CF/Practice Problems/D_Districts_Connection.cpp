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
        VI v(n, 0);

        rep (i, 0, n) cin >> v[i];

        auto max_v = max_element(all(v));
        auto min_v = min_element(all(v));

        if (*max_v == *min_v) { cout << "NO" << endl; continue; }
        else { cout << "YES" << endl; }

        map<int, VI> m;

        rep (i, 0, n) m[v[i]].pb(i);

        int minv = *min_v;
        int maxv = *max_v;
        int first_idx = m[minv][0];

        for (auto& it : m) {
            if (it.fi == minv) continue;
            
            for (int i : m[it.fi]) {
                cout << first_idx + 1 << " " << i + 1 << endl;
            }
        }

        for (int i : m[minv]) {
            if (i == first_idx) continue;
            cout << m[maxv][0] + 1 << " " << i + 1 << endl;
        }
    }

    return 0;
}