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



int is_stable(vector<vector<int>> dp, string s, int i, int j, char prev) {
    if (i > j) return 1;

    if (i==j) {
        if (s[i] != prev) return 1;
        if (s[i] == prev) return -1;
    }

    if ((j-i)%2!=0) {
        if (s[i] == s[j] && s[i] != '?' && s[j] != '?') return -1;
    }
    else {
        if (s[i] != s[j] && s[i] != '?' && s[j] != '?') return -1;
    }

    if (dp[i][j] != 0) return dp[i][j];

    dp[i][j] = is_stable(dp, s, i+1, j-1, s[i]);

    return dp[i][j];
}



int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length(), count=0;

        rep (i, 0, n) {
            rep (j, i+1, n) {
                if (is_stable(vector<VI>(n, VI(n, 0)), s, i, j, s[i]) == 1) {
                    count++;
                }
            }
        }


        cout << count+s.length() << endl;
    }

    return 0;
}

