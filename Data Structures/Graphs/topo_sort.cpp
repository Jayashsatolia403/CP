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


VI result;

void dfs(set<int> &vis, map<int,VI> graph, int cur) {
    if (vis.count(cur)) return;

    vis.insert(cur);

    for (int i : graph[cur]) {
        dfs(vis, graph, i);
    }

    result.pb(cur);
}

    
int main() {
    map<int,VI> graph;
    set<int> vis;

    graph.insert(mp(5,VI{0,2}));
    graph.insert(mp(4,VI{1,0}));
    graph.insert(mp(2,VI{3}));
    graph.insert(mp(3,VI{1}));
    graph.insert(mp(0,VI{}));



    for (auto& it : graph) {
        if (vis.count(it.fi)) continue;

        dfs(vis, graph, it.fi);
    }

    reverse(all(result));

    for (int i : result) cout << i << " ";
    
    return 0;
}