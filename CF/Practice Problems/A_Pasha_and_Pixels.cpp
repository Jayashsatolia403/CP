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
int n,m,k;


int main() {
    cin >> n >> m >> k;

    vector<vector<bool>> v(n, vector<bool>(m, false));

    int result = 0;

    rep (i, 0, k) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if (x > 0 && y < m-1 && (v[x-1][y] && v[x][y+1] && v[x-1][y+1])) {
            result = i+1;
            break;
        }
        else if (x < n-1 && y > 0 && (v[x+1][y] && v[x][y-1] && v[x+1][y-1])) {
            result = i+1;
            break;
        }
        else if (x > 0 && y > 0 && (v[x-1][y] && v[x][y-1] && v[x-1][y-1])) {
            result = i+1;
            break;
        }
        else if (x < n-1 && y < m-1 && (v[x+1][y] && v[x][y+1] && v[x+1][y+1])) {
            result = i+1;
            break;
        }


        v[x][y] = true;
    }

    cout << result << endl;

    return 0;
}