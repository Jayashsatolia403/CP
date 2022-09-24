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
        VI v(n);
        bool is_mod_5 = false;

        rep (i,0,n) {
            cin >> v[i];
            if (v[i]%5 == 0) is_mod_5 = true;
        }

        if (*max_element(all(v)) - *min_element(all(v)) == 0) {
            cout << "Yes" << endl;
        }
        else if (is_mod_5) {
            bool f = false;
            
            int idx = 0;
            for (int i : v) {
                if (i%5 != 0) {
                    cout << "No" << endl;
                    f = true;
                    break;
                }
                else {
                    if (i%10 == 5) v[idx] += 5;
                }
                idx++;
            }

            if (!f) {
                bool done = false;
                for (int i : v) {
                    if (i != v[0]) {
                        done = true;
                        cout << "No" << endl;
                        break;
                    }
                }
                if (!done) cout << "Yes" << endl;
            }
        }
        else {
            bool flag = false;

            rep (i, 0, n) {
                int x = v[i];

                while (x%10 != 2) {
                    x += x%10;
                }

                v[i] = x;
            }

            rep (i,1,n) {
                if ((v[i]-v[i-1])%20) flag = true;
            }

            cout << (flag ? "No" : "Yes") << endl;
        }
    }
    
    return 0;
}