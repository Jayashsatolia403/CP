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
        VI v(n);
        rep(i,0,n) cin >> v[i];

        int count = 0;

        bool done = false;

        int last = 0;

        rep (i, 0, n) {
            if (v[i] == 0) {
                if (last != 0) {
                    count++;
                    last = 0;
                }
            }
            else {
                done=true;
                last = -1;
            }
        }

        if (last == 0) count--;
        if (!done) {cout << 0 << endl; continue;}

        cout << (count > 0 ? 2 : 1)<< endl;
    }
    
    return 0;
}