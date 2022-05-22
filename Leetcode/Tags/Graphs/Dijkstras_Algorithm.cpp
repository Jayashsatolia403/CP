#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m, source;
	cin >> n >> m;

	// graph initialization
	vector<pair<int,int>> g[n+1];

	int a, b, wt;

	for (int i=0; i < m; i++) {
		cin >> a >> b >> wt;

		g[a].push_back(make_pair(b, wt));
		g[b].push_back(make_pair(a, wt));
	}

	cin >> source;

	// Dijkastra Algorithm starts here 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
	vector<int> dist_to(n+1, INT_MAX);

	dist_to[source] = 0;
	pq.push(make_pair(0, source));

	while (!pq.empty()) {
		int dist = pq.top().first;
		int prev = pq.top().second;

		pq.pop();

		vector<pair<int, int>>::iterator it;

		for (auto it : g[prev]) {
			int next = it.first;
			int next_dist = it.second;

			if (dist_to[next] > dist+next_dist) {
				dist_to[next] = dist_to[prev]+next_dist;
				pq.push(make_pair(dist_to[next], next));
			}
		}
	}

	for (int i : dist_to) cout << i << " > ";

	return 0;
}