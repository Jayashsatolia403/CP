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


// int lcs(string X, string Y)
// {
//     // int m = SZ(X);
//     // int n = SZ(Y);

//     int m = X.length();
//     int n = Y.length();

//     int L[m + 1][n + 1];
//     int i, j;
  
//     /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
//       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
//     for (i = 0; i <= m; i++) {
//         for (j = 0; j <= n; j++) {
//             if (i == 0 || j == 0)
//                 L[i][j] = 0;
  
//             else if (X[i - 1] == Y[j - 1])
//                 L[i][j] = L[i - 1][j - 1] + 1;
  
//             else
//                 L[i][j] = max(L[i - 1][j], L[i][j - 1]);
//         }
//     }
  
//     /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
//     return L[m][n];
// }


    
int main() {
    int t;
    cin >> t;
    
    rep (_, 1, t+1) {
        string a,b;
        cin >> a >> b;

        if (a.empty()) { cout << "Case #" << _ << ": " << b.length() << endl; continue; }
        else if (b.empty()) { cout << "Case #" << _ << ": " << "IMPOSSIBLE" << endl; continue; }

        int result = 0;

        for (char c : b) if (c == a[0]) result++;

        if (result >= SZ(a)) cout << "Case #" << _ << ": " << SZ(b) - SZ(a) << endl;
        else cout << "Case #" << _ << ": " << "IMPOSSIBLE" << endl;

        // // int diff = lcs(a,b) - a.length();

        // if (diff == 0) {
        //     cout << "Case #" << _ << ": " << b.length()-a.length() << "\n";
        // } else {
        //     cout << "Case #" << _ << ": " << "IMPOSSIBLE\n";
        // }
    }
    
    return 0;
}