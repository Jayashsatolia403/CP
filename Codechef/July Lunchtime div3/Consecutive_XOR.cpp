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
        string a, b;
        cin >> a >> b; 

        if (n == 2) {
            if (a != b) {
                if (a[0] == b[0] == 0) cout << "NO" << endl;
                else if (b[0] != b[1]) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            else cout << "YES" << endl;
        }
        else {
            bool is_zero = true;
            for (char c : a) if (c != '0') is_zero = false;

            if (is_zero) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    
    return 0;
}