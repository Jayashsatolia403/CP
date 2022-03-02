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



void flip(vector<VI>& v) {
    rep (i, 0, n) {
        rep (j, 0, m/2) {
            swap(v[i][j], v[i][m-j-1]);
        }
    }
}


vector<VI> rotate(vector<VI> a) {
    int n = a.size();
    int m = a[0].size();
    vector<VI> result(m, VI(n, 0));


    rep (i, 0, n) {
        rep (j, 0, m) {
            result[j][n-i-1] = a[i][j];
        }
    }

    // cout << result.size() << " >>>>> " << SZ(result[0]) << endl;

    return result;
}
    
    
int main() {
    int t;
    cin >> t;
    
    rep (_, 1, t+1) {
        cin >> n >> m;
        vector<VI> v(n, VI(m, 0));
        rep (i, 0, n) rep(j, 0, m) cin >> v[i][j];

        int result = 0;

        rep (moves, 1, 9) {

            cout << v.size() << " >>> " << v[0].size() << endl;
            
            rep (i, 0, n) {
                rep (j, 0, m) {
                    if (i > 0 && v[i][j] == 1 && v[i-1][j] == 1 && j < m-1 && v[i][j+1] == 1) {
                        int bigs=0,smalls=0, backup_i=i, backup_j=j;

                        while (backup_i >= 0 && v[backup_i][backup_j] == 1) {
                            bigs++;
                            backup_i--;
                        }

                        backup_i = i;
                        backup_j = j;
                        
                        while (backup_j < m && v[backup_i][backup_j] == 1) {
                            smalls++;
                            backup_j++;
                        }

                        int temp = bigs;
                        bigs = max(bigs, smalls);
                        smalls = min(temp, smalls);

                        if (bigs/2 < smalls) result += bigs/2-1;
                        else result += smalls-1;
                    }
                }
            }

            if (moves % 2 == 1) { flip(v); continue; }
            
            vector<VI> f = rotate(v); 
            cout << SZ(f) << " >< " << SZ(f[0]) << endl; 
            vector<VI> v;
            copy(all(f), back_inserter(v));

        }

        cout << "Case #" << _ << ": " << result << endl;
    }
    
    return 0;
}