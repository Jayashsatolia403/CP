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



vector<VI> result;


bool verify(VI v) {

    rep (i, 2, v.size()) {
        if (v[i-1] + v[i-2] == v[i]) return false;
    }

    return true;
}


set<int> vis;

void permute(int n, VI cur) {
    if (cur.size() == n) {
        if (verify(cur)) {
            result.pb(cur);
        }

        return;
    }

    for (int i=1; i <= n; i++) {
        if (vis.find(i) == vis.end()) {
            cur.pb(i);
            vis.insert(i);

            permute(n, cur);

            vis.erase(i);
            cur.pop_back();
        }
    }
}

    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;

        // vector<VI> result;
        // VI vis;

        VI cur;

        permute(n, cur);

        rep (i, 0, result.size()) {
            rep (j, 0, result[0].size()) cout << result[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}