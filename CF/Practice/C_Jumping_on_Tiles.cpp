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
        string s;
        cin >> s;

        int n = s.size();

        vector<int> v;

        int start=s[0]-'a', end=s[n-1]-'a';

        for (char c : s) {
            v.push_back(c-'a');
        }

        sort(v.begin(), v.end());

        vector<int> rev(v);

        reverse(rev.begin(), rev.end());

        int count1 = 0, count2 = 0, ans1=0, ans2=0;

        vector<int> result1, result2;

        int idx = 0;

        for (int i : v) {
            idx++; 
            if (i < start) continue;

            if (i > end) continue;

            count1++;
            ans1 += i;
            result1.push_back(idx);
        }

        idx = 0;

        for (int i : rev) {
            idx++;
            if (i > start) continue;

            if (i < end) continue;

            count2++;
            ans2 += i;
            result2.push_back(idx);
        }

        if (count1 > count2) {
            for (int i : result1) cout << i << " ";
            cout << endl;
        }
        else {
            for (int i : result2) cout << i << " ";
            cout << endl; 
        }
    }
    
    return 0;
}