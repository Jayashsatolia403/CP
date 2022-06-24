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
        VI v(n, 0);
        rep(i, 0, n) {
            cin >> v[i];
        }

        int left = 0, right = 0, sum = 0, result=-1;

        while (left < n && right < n) {
            sum += v[right];

            while (sum > m) {
                sum -= v[left];
                left++;
            }

            if (sum == m) {
                result = max(result, right - left + 1);
            }

            if (sum <= m) {
                right++;
            } 
        }

        cout << (result == -1 ? -1 : n - result) << endl;
    }
    
    return 0;
}