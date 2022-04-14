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
    int T;
    cin >> T;
    
    rep(t, 1, T+1) {
        string s;
        cin >> s;

        int result = INT_MAX;

        int digits = 0, f = n;
        while (f) {
            f /= 10;
            digits++;
        }

        rep (i, 0, digits+1) {
            rep (j, 0, 10) {
                int l = pow(10, i);

                if (i == digits && j == 0) continue;

                int x = ((n/l)*10 + j)*l + (n%l);

                // cout << x << endl;

                if (x%9 == 0) result = min(result, x);
            }
        }

        cout << "Case #" << t << ": " << result << endl;
    }
    
    return 0;
}