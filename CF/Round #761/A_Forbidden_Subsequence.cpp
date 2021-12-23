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


bool check_sorted(string s) {
    rep (i, 0, s.size()-1) {
        if (s[i] > s[i+1]) return false;
    }

    return true;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        char m, n, o;

        map<char,int> hashmap;

        for (char c: a) hashmap[c]++;

        if (hashmap.count('a') == 0 || hashmap.count('b') == 0 || hashmap.count('c') == 0) {
            sort(all(a));
            cout << a << endl;
            continue;
        }

        if (check_sorted(b)) {
            m = b[0];
            n = b[2];
            o = b[1];
        }
        else {
            m = 'a';
            n = 'b';
            o = 'c';
        }


        rep (i, 0, hashmap[m]) {
            cout << m;
        }

        rep (i, 0, hashmap[n]) {
            cout << n;
        }

        rep (i, 0, hashmap[o]) {
            cout << o;
        }

        for (pair<char, int> pr: hashmap) {
            if (pr.first != 'a' && pr.first != 'b' && pr.first != 'c') {
                rep (i, 0, pr.second) {
                    cout << pr.first;
                }
            }
        }

        cout << endl;
    }

    return 0;
}
