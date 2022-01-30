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
        cin >> n >> m;

        vector<int> v(26, 0);

        rep (i, 0, n) {
            char c;
            cin >> c;

            v[c-'a']++;
        }

        int total=0, individuals = 0, result=0;

        rep (i, 0, 26) {
            total += v[i]/2;
            individuals += v[i]%2;
        }

        result = 2 * (total / m);

        if (m <= individuals + 2*(total%m)) result++;

        cout << result << endl;
    }

    return 0;
}


// LOGIC : Make Pairs of each character and then assign each pair to each color equallly and if remaining pair elements and individuals 
// are greater than or equal to colors then we need to add that to our resulting string as per question. so we can add one more element 
// result variable and print it.