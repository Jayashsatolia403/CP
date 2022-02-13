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
    cin >> n;
    vector<VI> v(n, VI(3, 0));

    rep (i, 0, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vector<VI> dp(n, VI(3, 0));

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    rep (i, 1, n) {
        rep (j, 0, 3) {
            int a = 0, b = 0;

            if (j==0) { a = 1; b = 2; }
            else if (j==1) { a = 0; b = 2;}
            else if (j==2) { a = 0; b = 1;}

            dp[i][j] = max(dp[i-1][a], dp[i-1][b]);
            dp[i][j] += v[i][j];
        }
    }

    cout << *max_element(all(dp[n-1])) << endl;


    return 0;
}