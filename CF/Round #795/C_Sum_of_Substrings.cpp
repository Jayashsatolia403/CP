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
        string s;
        cin >> s;

        ll first_one_idx=0, last_one_idx=0, count=0, result=0;

        rep (i, 1, n-1) {
            if (s[i]=='1') {
                if (first_one_idx==0) first_one_idx = i;
                last_one_idx = i;
                count++;
            }
        }
        
        if (s[0] == '1') result += 10;
        if (s[n-1] == '1') result += 1;

        last_one_idx = n-last_one_idx-1;

        if (s[n-1] != '1' && count > 0) {
            if (m >= last_one_idx) {
                result += 1;
                count--;
                m -= last_one_idx;
            }
        }

        if (s[0] != '1'  && count > 0) {
            if (m >= first_one_idx) {
                result += 10;
                count--;
            }
        }

        if (count < 0) count = 0; 

        result += count*11 ;

        cout << result << endl;
    }
    
    return 0;
}