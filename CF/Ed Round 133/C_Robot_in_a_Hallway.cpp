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


int check_end(vector<VI> v, int i, int j, bool up, int sec) {

    rep (x, j+1, n) {
        sec += v[i][x]-sec > 0 ? v[i][x]-sec : 0;
        sec++;
    }

    if (up) i++;
    else i--;

    per (x, j+1, n) {
        sec += v[i][x]-sec > 0 ? v[i][x]-sec : 0;
        sec++;
    }

    return sec;
}

int dfs(vector<VI> v, int i, int j, bool left, bool vertical, int sec) {
    int n = v.size();

    if (i < 0 || j < 0 || i >= 2 || j >= n) return sec;

    int result = 0;

    int right_diff = v[i][j+1] - sec;
    right_diff = right_diff > 0 ? right_diff : 0;

    if (left) {
        if (i == 1) {
            // int up_diff = v[i-1][j] - sec;
            // up_diff = up_diff > 0 ? up_diff : 0;
            result = min(dfs(v, i-1, j, false, true, max(v[i-1][j], sec+1)), check_end(v, i, j, false, sec+1));
        }
        else {
            // int down_diff = v[i+1][j] - sec;
            // down_diff = down_diff > 0 ? down_diff : 0;
            result = min(dfs(v, i+1, j, false, true, max(v[i+1][j], sec+1)), check_end(v, i, j, true, sec+1));
        }
    }
    else if (vertical) {
        result = min(dfs(v, i+1, j, true, false, max(v[i][j+1], sec+1)), check_end(v, i, j, i==0, sec+1));
    }

    return result;
}


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<VI> v(2, VI(n));
        rep (i, 0, n) cin >> v[0][i];
        rep (i, 0, n) cin >> v[1][i];

        cout << dfs(v, 0, 0, true, false, 0) << endl;
    }
    
    return 0;
}