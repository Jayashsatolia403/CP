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


bool check(int a, int b) {
    if (a > b) return false;
    if (a == b) return true;

    int diff = b - a;

    if (diff % 3 == 0) {
        return true;
    }

    return false;
}
    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        string s;
        cin >> s;

        int count = 0;

        rep (i, 0, n) {
            int a=0, b=0;

            rep (j, i, n) {
                if (s[j] == '+') a++;
                else b++;

                if (check(a, b)) count++;
            }
        }

        cout << count << endl;
    }
    
    return 0;
}