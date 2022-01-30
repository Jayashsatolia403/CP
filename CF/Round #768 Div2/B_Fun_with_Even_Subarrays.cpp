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
        cin >> n;

        VI v(n, 0);
        rep (i, 0, n) cin >> v[i];

        set<int> s;

        rep (i, 0, n) {
            s.insert(v[i]);
        }

        int idx = 0, cnt = s.size();

        if (s.size() == 1) { cout << 0 << endl; continue; }

        while (idx < cnt) {
            int diff = pow(2, idx);
            cnt -=  diff;
            idx++;
        }

        cout << idx << endl;

    }

    return 0;
}