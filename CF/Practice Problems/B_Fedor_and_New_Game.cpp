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

    int res = 0;

    VI v(m+1, 0);

    rep (i, 0, m+1) cin >> v[i];

    string s = bitset<64>(v[m]).to_string();


    rep (i, 0, m) {
        string x = bitset<64>(v[i]).to_string();

        bool done = false;
        int cnt = k;

        rep (j, 0, 64) {
            if (cnt < 0) { done = true; break; }
            if (x[j] != s[j]) cnt--;
        }

        if (!done && cnt >= 0) res++;
    }

    cout << res << endl;

    return 0;
}