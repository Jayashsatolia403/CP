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
        int n, k, score = 0;
        cin >> n >> k;

        VI v(n, 0);

        rep (i, 0, n) {
            cin >> v[i];
        }

        sort(all(v));

        VI useful;

        rep (i, n-(2*k), n) {
            useful.push_back(v[i]);
        }

        rep (i, 0, n-(2*k)) score += v[i];

        rep (i, 0, k) {
            score += useful[i]/useful[k+i];
        }

        // int x = n-(2*k);
        // int cnt = 1;

        // rep (i, 0, x/2) {
        //     score += v[n/2+cnt] + v[n/2-cnt];
        //     cnt++;
        // }

        // if (x%2 != 0) score += v[n/2];

        cout << score << endl;
    }

    return 0;
}


