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
    int t;
    cin >> t;

    while (t--) {
        VI v(7, 0);

        rep (i, 0, 7) cin >> v[i];

        int m = *max_element(all(v));

        if (v[0] + v[1] + v[2] == m) cout << v[0] << " " << v[1] << " " << v[2];
        else if (v[0] + v[1] + v[3] == m) cout << v[0] << " " << v[1] << " " << v[3];
        else if (v[0] + v[2] + v[3] == m) cout << v[0] << " " << v[2] << " " << v[3];
        else if (v[1] + v[2] + v[3] == m) cout << v[1] << " " << v[2] << " " << v[3];
        else cout << "Error";

        cout << endl;
    }

    return 0;
}


