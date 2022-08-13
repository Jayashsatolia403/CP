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

int ans = INT_MAX;

int dfs(ll n, ll x, int steps) {

    string s = to_string(x);

    int len = s.size();
    if (n-s.size()+steps >= ans) return INT_MAX;

    if (len >= n) {
        ans = min(ans, steps);
        return ans;
    }


    VI v(10, 0);

    for (char c : s) {
        v[c-'0']++;
    }

    int result = INT_MAX;

    for (int i=9; i >= 2; i--) {
        if (v[i]) {
            result = min(result, dfs(n, i*x, steps+1));
        }
    }

    return result;
}
    
int main() {
    ll n, x;
    cin >> n >> x;

    int result = dfs(n, x, 0);

    cout << (result == INT_MAX ? -1 : result) << endl;

    return 0;
}