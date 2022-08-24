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
    
    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;

        cin >> n >> m;
        VI v(n);
        rep (i, 0, n) cin >> v[i];

        VI winners(n, v[0]);

        rep (i, 1, n) winners[i] = max(winners[i-1], v[i]);

        rep (i, 0, m) {

            int a, b;
            cin >> a >> b;
            a--;

            if (a > b || winners[a] != v[a]) {cout << 0 << endl; continue; }
            b-=a;

            int winner = v[a];

            int boost = a != 0;

            int check_last = upper_bound(winners.begin()+a+1, winners.end(), winner) - winners.begin();

            int result = 0;

            if (check_last != n) {
                result += check_last-a-1;
                cout << min(result, b)+boost << endl;
            }
            else {
                int check_start = upper_bound(winners.begin(), winners.begin()+a, winner) - winners.begin();
                
                if (check_start == a) {
                    cout << b+boost << endl;
                }
                else {
                    result += check_start;
                    cout << min(result, b)+boost << endl;
                }
            }
        }
    }
    
    return 0;
}