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
        vector<string> v(n);
        rep (i, 0, n) cin >> v[i];

        int count = 0, good = false, aval_zero=false;

        rep (i, 0, n) {
            rep (j, 0, m) {
                count += v[i][j] == '1';

                if (v[i][j] == '0') {
                    aval_zero = true;
                    if (i < n-1 && v[i+1][j] == '0') {good = true;} 
                    if (j < m-1 && v[i][j+1] == '0') {good = true;} 
                    if (i < n-1 && j < m-1 && v[i+1][j+1] == '0') {good = true;} 
                    if (i < n-1 && j > 0 && v[i+1][j-1] == '0') {good = true;} 
                    if (i > 0 && j > 0 && v[i-1][j+1] == '0') {good = true;} 
                    if (i > 0 && j > 0 && v[i-1][j-1] == '0') {good = true;} 
                }
            }
        }

        if (count == 0) cout << 0 << endl;
        else if (!aval_zero) cout << count-2 << endl; 
        else if (!good) cout << count - 1 << endl;
        else cout << count << endl;
    }
    
    return 0;
}