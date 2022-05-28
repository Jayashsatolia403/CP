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
    int T;
    cin >> T;
    
    rep (t, 1, T+1) {
        cin >> n;
        string s;
        cin >> s;

        bool c1=s.size()>=7, c2 = false, c3 = false, c4 = false, c5 = false;

        for (char c : s) {
            // if c is uppercase alphabet
            if (c>='A' && c<='Z') {
                c2 = true;
            }
            // if c is lowercase alphabet
            else if (c>='a' && c<='z') {
                c3 = true;
            }
            // if c is digit
            else if (c>='0' && c<='9') {
                c4 = true;
            }
            // if c is special character
            else {
                c5 = true;
            }
        }

        if (!c2) s += 'A';
        if (!c3) s += 'a';
        if (!c4) s += '0';
        if (!c5) s += '&';
        if (!c1) {
            rep (i, 0, 7-s.size()) s += 'a';
        }

        cout << "Case #" << t << ": " << s << endl;
    }
    
    return 0;
}