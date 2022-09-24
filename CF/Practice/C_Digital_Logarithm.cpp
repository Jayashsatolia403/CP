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


int count_digits(int x) {
    if (x == -1) return 0;
    int count = 0;
    while (x) {
        count++;
        x/=10;
    }
    return count;
}
    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI a(n), b(n);
        rep (i, 0, n) cin >> a[i];
        rep (i, 0, n) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int l=0, r=0;

        while (l < n && r < n) {
            if (a[l] == b[r]) {
                a[l++] = -1;
                b[r++] = -1;
            }
            else if (a[l] < b[r]) l++;
            else r++;
        }

        // for (int i : a) cout << i << " ";
        // cout << endl;
        // for (int j : b) cout << j << " ";
        // cout << endl;


        VI x(10), y(10);

        int cnt = 0;

        for (int i : a) {
            if (count_digits(i)==1){
                x[i]++;
                cnt+=(bool)(i-1);
            }
            else x[count_digits(i)]++;
        }

        for (int i : b) {
            if (count_digits(i)==1){
                y[i]++;
                cnt+=(bool)(i-1);
            }
            else y[count_digits(i)]++;
        }
        
        int result = 0;

        rep (i, 2, 10) {
            result += x[i]+y[i];
            result += abs(x[i]-y[i]);
        }

        result -= cnt;

        cout << result << endl;
    }
    
    return 0;
}