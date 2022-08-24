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
        string s;
        cin >> s;
        int n = s.size();

        vector<PII> forward, backward;

        int count0=0, count1=0;

        rep (i,0,n) {
            if (s[i] == '0') count0++;
            else count1++;
        }

        int cur0=0, cur1=0;

        rep (i, 0, n) {
            if (s[i]=='0') forward.push_back({cur0++, cur1});
            else forward.push_back({cur0, 1+cur1++});
        }

        cur0=0;
        cur1=0;

        per (i, 0, n) {
            if (s[i]=='0') backward.push_back({cur0++, cur1});
            else backward.push_back({cur0, 1+cur1++});
        }

        // reverse(all(backward));

        int diff = INT_MAX;
        int good_diff = min(count0, count1);

        rep (i, 0, n) {
            PII p = forward[i];
            
            rep (j, 0, n) {
                PII p2 = backward[j];

                diff = min(diff, max(count0 - (p.fi+p2.fi), (p.se+p2.se)));
                good_diff = min(good_diff, max(count0-p.fi, p.se));
                good_diff = min(good_diff, max(count0-p2.fi, p2.se));
            }
        }

        cout << min(good_diff, (diff>0?diff-1:0)) << endl;
    }
    
    return 0;
}