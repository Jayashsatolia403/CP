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
        int n;
        cin >> n;
        VI v(n, 0);

        rep (i, 0, n) {
            cin >> v[i];
        }

        int final_sum = INT_MIN, cur_sum = INT_MIN;
        VI max_sum_subarray;


        int first_idx, last_idx;

        bool done = false;

        rep (i, 0, n) {
            if (v[i] > cur_sum) {
                cur_sum = v[i];
                done = true;
            }
            else {
                cur_sum += v[i];
            }
            
            if (final_sum < cur_sum) {
                final_sum = cur_sum;
                if (done) {
                    first_idx = i;
                    done = false;
                }
                last_idx = i;
            }

            final_sum = max(final_sum, cur_sum);

        }

        rep (i, first_idx, last_idx+1) {
            cout << v[i] << " ";
        }


        cout << endl;
    }
}