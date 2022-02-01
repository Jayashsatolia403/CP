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
        VI v(n, 0), pos, neg, arr;

        rep (i, 0, n) cin >> v[i];

        int cnt_zeros=0;

        // seperate postive and negative numbers
        rep (i, 0, n) {
            if (v[i] > 0) pos.pb(v[i]);
            else if (v[i] < 0) neg.pb(v[i]);
            else cnt_zeros++;
        }

        sort(all(pos));
        sort(all(neg));
        reverse(all(neg));

        int idx = 0;
        if (neg.size() % 2) { idx = 1; }
        else idx = 0;
        int remaining_neg = neg[0];

        rep (i, 0, (neg.size())/2) {
            arr.pb(neg[idx] * neg[idx + 1]);
            idx += 2;
        }

        int remaining_pos1=0, remaining_pos2=0;

        if (pos.size() > 0) {
            if (pos.size() % 2) idx = 1;
            else idx = 2;
            remaining_pos1 = pos[0];
            remaining_pos2 = idx > 1 ? pos[idx-1] : 0;

            rep (i, 0, (pos.size() - idx + 1)/2) {
                arr.pb(pos[idx] * pos[idx + 1]);
                idx += 2;
            }
        }

        sort(all(arr));

        // rep (i, 0, arr.size()) cout << arr[i] << " ";
        // cout << endl;

        int arr_len = arr.size();

        if (arr_len < 2) {
            if (cnt_zeros) cout << 0 << endl;
            else cout << remaining_neg * remaining_pos1 * arr[arr_len-1] * remaining_pos2 << endl;
            continue;
        }

        int result = arr[arr_len-1] * arr[arr_len-2] * (remaining_pos1 != 0 ? max(remaining_pos1, remaining_pos2) : remaining_neg);

        cout << result << endl;
    }

    return 0;
}