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
        VI v(n);
        for (int i=0; i < n; i++) cin >> v[i];

        bool compromised = false;

        map<int, vector<int>> indexes;
        for (int i=0; i < n; i++) {
            indexes[v[i]].push_back(i);
        }
        
        set<int> count;

        int i = n-1;

        while (i >= 0) {
            if (i > indexes[v[i]][0]) {
                
                for (int j=indexes[v[i]][0]; j <= i; j++) {
                    if (v[j] != v[i]) {
                        compromised = true;
                        break;
                    }
                }

                if (compromised) {break;}
                else i = indexes[v[i]][0];
            }

            if (v[i] < v[i-1]) {
                i--;
                break;
            }

            i--;
        }

        for (int j=0; j <= i; j++) {
            count.insert(v[j]);
        }

        cout << count.size() << endl;
    }
    
    return 0;
}