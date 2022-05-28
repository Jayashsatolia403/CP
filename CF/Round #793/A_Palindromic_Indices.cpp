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




bool is_palindrome(string s, int x, int i, int j, vector<VI> &dp) {

    if (i == x) i++;
    if (j == x) j--;

    if (i >= j) return true;

    if (dp[i][j] != -1 && x < i && x > j) {
        return dp[i][j];
    }

    if (s[i] == s[j]) {
        dp[i][j] = is_palindrome(s, x, i+1, j-1, dp);
        return dp[i][j];
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

        vector<VI> dp = vector<VI>(n, VI(n, -1));

        for (int i = 0; i < n; i++) {
            bool x = is_palindrome(s, i, 0, n-1, dp);
            if (x) count++;
        }

        cout << count << endl;
    }
    
    return 0;
}