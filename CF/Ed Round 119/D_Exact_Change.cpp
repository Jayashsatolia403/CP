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



VI get_min_coins(int n) {
    VI v(3, 0);

    v[2] = n/3;
    n = n%3;
    v[1] = n/2;
    n = n%2;
    v[0] = n;


    // cout << v[0] << " > " << v[1] << " > " << v[2] << endl;

    return v;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        VI v(n, 0);
        
        rep (i, 0, n) cin >> v[i];

        VI min_coins(3, 0);

        sort(all(v));


        rep (i, 0, n) {
            int m = min_coins[0] + min_coins[1]*2 + min_coins[2]*3;

            VI x = get_min_coins(v[i] - m);

            rep (j, 0, 3) min_coins[j] += x[j];
        }

        // cout << min_coins[0] << " > " << min_coins[1] << " > " << min_coins[2] << endl;
        
        cout << (min_coins[0]==0?0:min_coins[0]/2+1) + min_coins[1] + min_coins[2] << endl;

    }

    return 0;
}
