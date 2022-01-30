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
    cin >> n >> m;
    VI v(n, 0);
    rep (i, 0, n) cin >> v[i];
    bool is_good = false;

    int saved_candies = 0, days=0;

    rep (i, 0, n) {
        if (v[i] > 8) {
            m -= 8;
            saved_candies += v[i]-8;
        }
        else {
            if (saved_candies > 0) {
                if (saved_candies > 8-v[i]) {
                    m -= 8;
                    saved_candies -= 8-v[i];
                }
                else {
                    m -= v[i] + saved_candies;
                    saved_candies = 0;
                }
            }
            else m -= v[i];
        }

        if (m <= 0) { days=i+1; break; }
    }

    days!=0 ? cout << days << endl : cout << -1 << endl;

    return 0;
}