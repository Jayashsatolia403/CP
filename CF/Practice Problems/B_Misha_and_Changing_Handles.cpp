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

    map<string, string> m;

    rep (i, 0, n) {
        string s1, s2;

        cin >> s1 >> s2;

        m[s1] = s2;
    }

    for (auto& it : m) {
        while (m.count(it.se)) {
            string s = it.se;
            it.se = m[it.se];
            m.erase(s);
        }
    }

    cout << m.size() << endl;

    for (auto& it : m) {
        cout << it.fi << " " << it.se << endl;
    }
    
    return 0;
}