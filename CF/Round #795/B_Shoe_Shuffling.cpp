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
        int a[n];
        rep(i,0,n) cin >> a[i];

        map<int, pair<int, vector<int>>> sizes;

        rep(i,0,n) {
            sizes[a[i]].fi++;
            sizes[a[i]].se.push_back(i);
        }

        bool done = false;

        for (auto&it : sizes) {
            if (it.se.fi < 2) {
                done = true;
                break;
            }
        }

        if (done) cout << -1 << endl;
        else {
            
            for (auto&it : sizes) {
                for (int i=1; i < it.se.fi; i++) {
                    cout << it.se.se[i]+1 << " ";
                }
                cout << it.se.se[0]+1 << " ";
            }

            cout << endl; 
        }
    }
    
    return 0;
}