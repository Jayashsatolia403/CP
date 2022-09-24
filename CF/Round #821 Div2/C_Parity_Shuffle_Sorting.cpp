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



int binary_search_lower_bound(vector<pair<int,int>> v, int target) {
    int l = 0;
    int r = v.size() - 1;
    int mid = (l + r) / 2;

    while (l < r) {
        if (v[mid].first < target) {
            l = mid + 1;
        }
        else {
            r = mid;
        }

        mid = (l + r) / 2;
    }

    return mid;
}
    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        VI v(n);
        rep (i, 0, n) cin >> v[i];

        vector<pair<int,int>> result;
        
        int n = v.size();
        
        
        for (int i=0; i < n; i++) {
            
            int idx=0;
            
            if (result.empty() || result[result.size()-1].first < v[i]) {
                result.push_back({v[i],i});
            }
            else {
                idx = binary_search_lower_bound(result, v[i]);
                result[idx] = {v[i],i};
            }
        }

        for (pair<int,int> i : result) {
            cout << i.second << " ";
        }
        cout << endl;
    }
    
    return 0;
}