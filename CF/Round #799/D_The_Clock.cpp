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
    

// is palindrome
bool is_palindrome(string s) {
    int n = SZ(s);
    rep (i, 0, n/2) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

    
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s >> n;

        int minutes = stoi(s.substr(3, 2));

        int hours = stoi(s.substr(0, 2));

        int count = 0;

        bool done = false;

        string str_hrs = to_string(hours), str_min = to_string(minutes);

        if (str_hrs.size() == 1) str_hrs = "0" + str_hrs;
        if (str_min.size() == 1) str_min = "0" + str_min;


        cout << str_hrs + ":" + str_min << endl;

        if (is_palindrome(str_hrs + ":" + str_min)) {
            // cout << hours << " > " << minutes << endl;
            count++;
        }

        minutes += n;

        while (true) {

            if (minutes >= 60) {
                hours += minutes / 60;
                minutes = minutes % 60;
            }

            hours = hours%24;

            if (hours == stoi(s.substr(0, 2)) && minutes == stoi(s.substr(3, 2))) break;

            string str_hrs = to_string(hours), str_min = to_string(minutes);

            if (str_hrs.size() == 1) str_hrs = "0" + str_hrs;
            if (str_min.size() == 1) str_min = "0" + str_min;


            // cout << str_hrs + ":" + str_min << endl;

            if (is_palindrome(str_hrs + ":" + str_min)) {
                // cout << hours << " > " << minutes << endl;
                count++;
            }
        }

        cout << count << endl;
    }
    
    return 0;
}