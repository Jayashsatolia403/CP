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
typedef map<int, int> MII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
 
const int N=201000;

bool comperator(PII& a, PII& b) {
    return a.first < b.first;
}

vector<PII> sort_map(MII hashmap) {
    vector<PII> A;

    for (auto& it: hashmap) {
        A.push_back(it);
    }


    sort(all(A));

    return A;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        VI a(n, 0), b(n, 0);
        
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];

        map<int,int> hashmap;

        rep (i, 0, n) {
            if (hashmap.count(a[i])) {
                hashmap[a[i]] += b[i];
            }
            else hashmap.insert(PII(a[i], b[i]));
        }


        vector<PII> v = sort_map(hashmap);

        rep (i, 0, v.size()) {
            if (v[i].first <= k) k += v[i].second;
        }

        cout << k << endl;        
    }

    return 0;
}