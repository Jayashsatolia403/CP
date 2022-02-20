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
        
        int x = 0, y = 0;
        
        bool done = false;
        
        rep (i, 0, n) {
        	if (v[i] > i+1) {
        		x = i;
        		done = true;
        	}
        	
        	if (done && v[i] == x+1) { y = i; break; } 
        }
        
        rep (i, 0, x) cout << v[i] << " ";
        per (i, x, y+1) cout << v[i] << " ";
        rep (i, y+1, n) cout << v[i] << " ";
        
        cout << endl;
    }
    
    return 0;
}

