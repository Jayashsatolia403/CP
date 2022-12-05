#include <bits/stdc++.h>
using namespace std;


map<pair<int,int>, int> g;


int dfs(int i, vector<int> &vis, vector<vector<int>> &adj) {
    
    vis[i] = true;
    int ans = 1;

    for (auto &it : adj[i]) {
        if (!vis[it]) {
            int x = dfs(it, vis, adj);
            ans += x;
            g[{min(i,it), max(i, it)}] = x*n-x;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    int len;
    cin >> len;

    for (int i=0; i < len; i++) {
        int a, b;
        cin >> a >> b;
    } 
}




















// cities connected by roads
#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;
int n;
int dfs(int i, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[i] = 1;
    
    int ans = 1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            int x = dfs(it,vis,adj);
            ans+=x;
            m[{min( i,it ), max( i,it )}] = x*(n-x);
        }
    }
    return ans;
}
int main()
{
   cin>>n;
   vector<vector<int>> adj(n+1);
   map<pair<int,int>,int> m1;
   int mm;
   cin>>mm;
   for(int i=0;i<mm;i++)
   {
       int u,v;
       cin>>u>>v;
       if( m1[{min(u,v) , max(u,v)}] > 0) continue;
       m1[{min(u,v) , max(u,v)}]++;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   vector<int> vis(n+1,0);
   dfs(1,vis,adj);
   int mx=-1, ans1, ans2;
   for(auto it:m)
   {
       if(it.second>mx)
       {
           mx=it.second;
           ans1 = it.first.first, ans2=it.first.second;
       }
   }
   cout<<ans1<<" "<<ans2;
   cout<<endl;
   return 0;
}