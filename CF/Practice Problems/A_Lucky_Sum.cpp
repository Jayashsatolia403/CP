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
string n,m,_;


ll get_lucky(ll n) {
    bool good = false, issue = false;

    string s = to_string(n);
    string result = "";


    int i=0, len = s.length();

    while (i < len) {
        if (s[i] != '4' && s[i] != '7') break;
        else result += s[i];
        i++;
    }

    if (i < n) {
        if (s[i] < '4') {
            rep (j, i, len) result += '4';
        }
        else if (s[i] > '4' && s[i] < '7') {
            result += '7';
            rep (j, i+1, len) result += '4';
        }
        else {
            int sz = result.length()-1;
            while (sz >= 0 && result[sz] == '7') {
                sz--;
            }

            if (sz < 0) {
                result = '4' + result; 
                
                rep(x, 0, result.length()) result[x] = '4';
            } 
            else { result[sz] = '7'; rep(x, sz+1, result.length()) result[x] = '4'; }


            rep (j, i, len) result += '4';
        }
    }

    // cout << n << " > " << result << endl;

    return stoll(result);
}


int main() {
    cin >> n >> m;

    ll result = 0;

    rep (i, n, m+1) {
        result += get_lucky(i);
    }
    
    cout << result << endl;


    return 0;
}