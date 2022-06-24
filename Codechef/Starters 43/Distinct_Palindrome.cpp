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
        cin >> n >> m;

        bool ok = true;

        if (n == 1 && m==1) {cout << "a" << endl; continue;}

        string result = "";

        if (n%2 == 0) {
            if (m > n/2 || m > 26) ok = false; 
            else {
                rep(i,0,m-1) {
                    result += 'a'+i;
                }

                rep(i,m,n/2+1) {
                    result += 'z';
                }

                string rev = result;
                reverse(all(rev));
                result += rev;
            }
        }
        else {
            if (m > n/2+1 || m > 26) ok = false;
            else {
                rep(i,0,m-1) {
                    result += 'a'+i;
                }

                rep(i,m,n/2+2) {
                    result += 'z';
                }

                string rev = result.substr(0,n/2);
                reverse(all(rev));
                result += rev;
            }
        }

        if (ok) cout << result << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}