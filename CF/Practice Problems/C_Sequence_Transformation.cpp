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
        VI v (n, 0), v2;

        rep (i, 0, n) cin >> v[i];

        rep (i, 0, n) {
            if (i != 0 && v[i] != v[i-1]) v2.pb(v[i]);
            else if (i == 0) v2.pb(v[i]);
        }

        map<int, int> hashmap;

        rep (i, 0, v2.size()) {
            if (hashmap.find(v2[i]) == hashmap.end()) hashmap[v2[i]] = 1;
            else hashmap[v2[i]]++;
        }

        n = v2.size();

        if (n==1) {cout << 0 << endl; continue;}

        hashmap[v2[0]]--;
        hashmap[v2[n-1]]--;

        int min_val = INT_MAX;

        for (auto& it : hashmap) {
            min_val = min(min_val, it.se);
        }

        cout << min_val+1 << endl;
    }

    return 0;
}