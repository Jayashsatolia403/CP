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


int get_min_cost(map<int, vector<pair<int,int>>> g, int n) {

    vector<int> cost(n, INT_MAX), mst(n, false), parent(n, -1);

    cost[0] = 0;
    mst[0] = true;

    int node = 0;

    set<int> vis;

    bool unchanged = false;

    while (!unchanged) {
        mst[node] = true;

        for (pair<int,int> p : g[node]) {
            
            if (mst[p.first]) continue;

            if (cost[p.first] <= p.second) continue;

            cost[p.first] = p.second;

            parent[p.first] = node;
        }

        int cur = INT_MAX;

        unchanged = true;

        for (int i=0; i < n; i++) {
            if (mst[i]) continue;

            if (cur > cost[i]) {
                cur = cost[i];
                node = i;
                unchanged = false;
            }
        }
    }

    int result = 0;

    for (int i : cost) result += i;

    return result;
}
    


int main() {

    int n=6;
    vector<VI> v = {{0, 1, 1, 100, 0, 0},
                    {1, 0, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0, 0},
                    {100, 0, 0, 0, 2, 2},
                    {0, 0, 0, 2, 0, 2},
                    {0, 0, 0, 2, 2, 0}};

    map<int,vector<pair<int,int>>> g;

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (v[i][j]) g[i].push_back({j, v[i][j]});
        }
    }

    cout << get_min_cost(g, n) << endl;

    return 0;
}