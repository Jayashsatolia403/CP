#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define p(a,b) pair<int,vector<int>>(a,b)





void print_set(set<int> hashset) {

    cout << "{ ";

    for (int it : hashset) {
        cout << it << " ";
    }

    cout << "}" << endl;
}


vector<int> result;



bool dfs(map<int, vector<int>> hashmap, int key, bool turn, set<int> visited_keys) {

    if (hashmap.count(key) == 0) {

        // print_set(visited_keys);

        return turn;
    }

    bool res = true;

    vector<int> v = hashmap[key];

    forn (i, v.size()) {
        
        if (visited_keys.count(v[i]) != 0) continue;

        visited_keys.insert(v[i]);

        res = dfs(hashmap, v[i], turn==true?false:true, visited_keys);
    }

    print_set(visited_keys);

    return res;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int,vector<int>> hashmap;


        forn (i, n-1) {
            int u, v;
            cin >> u >> v;

            vector<int> init_v(1, v);
            vector<int> init_u(1, u);

            if (hashmap.count(u) == 0) {
                hashmap.insert(p(u, init_v));
                hashmap.insert(p(v, init_u));
            } else {
                hashmap[u].push_back(v);
                hashmap[v].push_back(u);
            }
        }

        // print_map(hashmap);


        forn (i, n) {
            set<int> vis;
            
            vis.insert(i+1);

            bool dfs_res = dfs(hashmap, i+1, false, vis);

            // cout << dfs_res << endl;

            if (dfs_res) {

                cout << i << endl;
                
                // forn (f, result.size()) {
                //     cout << result[f] << " ";
                // }
            }
        }

        // cout << endl;
    }

    return 0;
}