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
        int64_t A, S;
        cin >> A >> S;
        string B;

        bool done = false;
    
        while (S > 0) {
            int64_t D = A % 10;
            int64_t SD = S % 10;
            int64_t BD = (10 + SD - D) % 10;
    
            if (D + BD == SD) {
                B = to_string(BD) + B;
                A /= 10;
                S /= 10;
            } else if (D + BD == S % 100) {
                B = to_string(BD) + B;
                A /= 10;
                S /= 100;
            } else {
                cout << -1 << '\n';
                done = true;
                break;
            }
        }

        if (done) continue;
    
        if (A != 0) {
            cout << -1 << '\n';
            continue;
        }
    
        while (B.size() > 1 && B.front() == '0')
            B = B.substr(1);
    
        cout << B << '\n';
    }

    return 0;
}
