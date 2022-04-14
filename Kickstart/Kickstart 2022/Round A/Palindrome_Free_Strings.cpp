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
    
    rep (T, 1, t+1) {
        cin >> n;
        string s;
        cin >> s;

        bool done = false;

        rep(i, 0, n) [
            string x = s.substr(i, 5);

            bool good = true;

            rep (j, 0, 2) {
                if (s[j] == s[4-j] && s[j] != '?') good = false;
            }

            if (!good) {
                cout << "Case #" << T << ": " << "IMPOSSIBLE" << endl;
                done = true;
                break;
            }
            else {
                int cnt = 0;

                rep (j, 0, 5) if (x[j] != '?' && j != 2) cnt++;

                rep (j, 0, 2) {
                    if (s[j] == '?' && s[j+1] != '?') {
                        if (s[4-j] == '?') continue;
                        else s[j] = s[4-j] == '1' ? '0' : '1';
                    }
                }
            }
        ]
    }
    
    return 0;
}