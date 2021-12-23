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
        int n;
        cin >> n;

        string s, x="";
        cin >> s;

        VI v(26, 0);

        rep (i, 0, SZ(s)) {
            v[s[i]-'a']++;
        }

        rep (i, 0, 26) {
            rep (j, 0, v[i]) {
                x += 'a' + i;
            }
        }

        // cout << x << endl;

        int res = 0;

        rep (i, 0, n) {
            if (s[i] != x[i]) res++;
        }

        cout << res << endl;
    }

    return 0;
}
