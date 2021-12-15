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

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

string decimalToBinary(ll n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<64> (n).to_string();
     
    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}

bool solve(string s, ll y, int cnt) {

    // cout << "YO" << endl;

    // cout << binaryToDecimal(s) << " > " << y << endl;

    if (binaryToDecimal(s) == y) return true;

    if (cnt == 22) return false;

    string f = s + '0';
    reverse(all(f));


    string g = s + '1';
    reverse(all(g));


    bool done = solve(f, y, cnt+1) || solve(g, y, cnt+1);

    return done;
}



int main() {
    ll x, y;
    cin >> x >> y;

    if (y%2 == 0) {
        cout << "NO";
        return 0;
    }

    string s = decimalToBinary(x);

    bool done = solve(s, y, 1);

    if (done) cout << "YES";
    else cout << "NO";
    return 0;
}


