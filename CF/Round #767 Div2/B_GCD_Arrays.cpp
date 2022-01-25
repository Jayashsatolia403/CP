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

int find_smallest_divisor(int n) {
    rep (i, 2, sqrt(n)+1) {
        if (n%i == 0) return i;
    }

    return -1;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;

        bool res = false;

        if (l == r && l != 1) res = true; 
        else {
            if (l%2) l--;
            if (r%2) r++;

            res = k >= (r-l)/2;
        }

        res ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}