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



void solve() {

}



int main() {
    int t, n, count=0;
    cin >> t;
    n = t;

    vector<VI> v;

    while (t--) {
        int h, a;
        cin >> h >> a;

        v.push_back({h, a});
    }

    rep (i, 0, n) {
        rep (j, i+1, n) {
            if ((v[i][1] == v[j][0] && v[i][0] == v[j][1])) {
                count += 2;
            }
            else if ((v[i][1] == v[j][0] || v[i][0] == v[j][1])) {
                count++;
            }
        }
    }

    cout << count;
}


