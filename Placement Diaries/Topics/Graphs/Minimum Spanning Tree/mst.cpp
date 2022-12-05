#include <bits/stdc++.h>
using namespace std;




int main() {
    int n;
    cin >> n;

    map<int, vector<pair<int,int>>> g;

    for (int i=0; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;

        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }


    vector<int> key(n+1, INT_MAX), parent(n+1, -1), mstSet(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    key[0] = 0;

    for (int i=0; i < n; i++) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto &it : g[u]) {
            int v = it.first;
            int weight = it.second;

            if (mstSet[v] == false && key[v] < weight) {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight; 
            }
        }
    }

    for (int i=0; i < n; i++) {
        cout << i << " - " << parent[i] << endl;
    }

    return 0;
}










































// #include <bits/stdc++.h>
// using namespace std;




// int main() {
//     int n;
//     cin >> n;
//     map<int, vector<pair<int,int>>> g;

//     for (int i = 0; i < n; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     vector<int> key(n+1, INT_MAX), parent(n+1, -1), mstSet(n+1, false);
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

//     pq.push({0, 0});
//     key[0] = 0;

//     for (int i=0; i < n; i++) {
//         pair<int,int> p = pq.top();
//         pq.pop();

//         int u = p.second;

//         for (auto &it : g[u]) {
//             int v = it.first;
//             int weight = it.second;

//             if (mstSet[v] == false && key[v] < weight) {
//                 parent[v] = u;
//                 pq.push({key[v], v});
//                 key[v] = weight;
//             }
//         }
//     }

//     for (int i=0; i < n; i++) {
//         cout << i << " - " << parent[i] << endl;
//     }

//     return 0;
// }


























































// // #include <bits/stdc++.h>
// // using namespace std;



// // int main() {
// //     int n;
// //     cin >> n;

// //     vector<vector<pair<int,int>>> adj(n);
    
// //     for (int i=0; i < n; i++) {
// //         int x, y, z;
// //         cin >> x >> y >> z;

// //         adj[x].push_back({y, z});
// //         adj[y].push_back({x, z});
// //     }

// //     vector<int> key(n, INT_MIN), mstSet(n, false), parent(n, -1);
// //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// //     pq.push({0, 0});
// //     key[0] = 0;

// //     for (int i=0; i < n-1; i++) {
// //         int u = pq.top().second;
// //         pq.pop();

// //         for (auto &it : adj[u]) {
// //             int v = it.first;
// //             int weight = it.second;

// //             if (mstSet[v] == false && weight < key[v]) {
// //                 parent[v]= u;
// //                 pq.push({key[v], v});
// //                 key[v] = weight;
// //             }
// //         }
// //     }

// //     for (int i=0; i < n; i++) {
// //         cout << i << " - " << parent[i] << endl;
// //     }

// //     return 0;
// // }




























// // // #include <bits/stdc++.h>
// // // using namespace std;



// // // int main() {
// // //     int n;
// // //     cin >> n;

// // //     vector<vector<pair<int,int>>> adj(n);

// // //     for (int i=0; i < n; i++) {
// // //         int x, y, z;
// // //         cin >> x >> y >> z;

// // //         adj[x].push_back({y, z});
// // //         adj[y].push_back({x, z});
// // //     }

    
// // //     vector<int> key(n, INT_MIN), mstSet(n, false), parent(n, -1);
// // //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// // //     pq.push({0, 0});

// // //     key[0] = 0;

// // //     for (int i=0; i < n-1; i++) {
// // //         int u = pq.top().second;
// // //         pq.pop();

// // //         for (auto &it : adj[u]) {
// // //             int v = it.first;
// // //             int weight = it.second;

// // //             if (mstSet[v] == false && weight < key[v]) {
// // //                 parent[v] = u;
// // //                 pq.push({key[v], v});
// // //                 key[u] = v;
// // //             }
// // //         }
// // //     }

// // //     for (int i=0; i < n; i++) {
// // //         cout << i << " - " << parent[i] << endl;
// // //     }

// // //     return 0;
// // // }























































// // // #include <bits/stdc++.h>
// // // using namespace std;


// // // int main() {
// // //     int n;
// // //     cin >> n;

// // //     vector<vector<pair<int,int>>> g(n);

// // //     for (int i=0; i < n; i++) {
// // //         int x, y, z;
// // //         cin >> x >> y >> z;

// // //         g[x].push_back(make_pair(y, z));
// // //         g[y].push_back(make_pair(x, z));
// // //     }

// // //     vector<int> parent(n, -1), key(n, INT_MAX), mstSet(n, false);

// // //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// // //     pq.push({0, 0});

// // //     key[0] = 0;

// // //     for (int i=0; i < n-1; i++) {
        
// // //         int u = pq.top().second;
// // //         pq.pop();

// // //         mstSet[u] = true;

// // //         for (auto &it : g[u]) {
// // //             int v = it.first;
// // //             int weight = it.second;

// // //             if (mstSet[v] == false && weight < key[v]) {
// // //                 parent[v] = u;
// // //                 pq.push({key[v], v});
// // //                 key[v] = weight;
// // //             }
// // //         }
// // //     }

// // //     for (int i=0; i < n; i++) {
// // //         cout << parent[i] << " - " << i << endl;
// // //     }

// // //     return 0;
// // // }