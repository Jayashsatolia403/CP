#include <bits/stdc++.h>
using namespace std;



class EfficientSolution {
public:
	int ladderLength(string a, string b, vector<string>& v) {

		queue<string> q;
		q.push(a);

		set<string> words, vis;
		for (string s: v) words.insert(s);

		int result = 1;

		while (!q.empty()) {
			int n = q.size();

			for (int i=0; i < n; i++) {
				string s = q.front();
				q.pop();

				if (s == b) return result;

				for (int j=0; j < s.length(); j++) {
					string t = s;
					for (int c='a'; c <= 'z'; c++) {
						t[j] = c;

						if (words.count(t) && !vis.count(t)) {
							q.push(t);
							vis.insert(t);
						}
					}
				}
			}

			result++;
		}

		return 0;
	}
};





// Time Complexity : n^2 + n*m
class Solution {
public:
	map<string, vector<string>> g;

	int diff(string a, string b) {
		int result = 0;

		for (int i=0; i < a.length(); i++) if (a[i] != b[i]) result++;

		return result;
	}

    int ladderLength(string b, string e, vector<string>& v) {
        int n = v.size(), m = b.length();

        for (int i=0; i < n; i++) if (diff(b, v[i]) <= 1) {
        	if (g.find(b) == g.end()) {
        		vector<string> temp;
        		g[b] = temp;
        	}
        	g[b].push_back(v[i]);
        }

        for (int i=0; i < n; i++) {
        	for (int j=0; j < n; j++) {

        		if (diff(v[i], v[j]) <= 1) {
        			if (g.find(v[i]) == g.end()) {
	        			vector<string> temp;
	        			g[v[i]] = temp;
	        		}
	        		g[v[i]].push_back(v[j]);
	        	}
        	}
        }


        queue<pair<string, int>> q;
        q.push({b, 1});



        map<string,bool> vis;

        while (!q.empty()) {
        	pair<string, int> p = q.front();
        	string s = p.first;
        	int idx = p.second;
        	q.pop();

        	vis[s] = true;


        	vector<string> check = g[s];
        	int len = check.size();

        	for (int i=0; i < len; i++) {
        		if (!vis[check[i]]) {
        			q.push({check[i], idx+1});

        			if (check[i] == e) return idx+1;
        		}
        	}
        }

        return 0;
    }
};



int main() {
	string begin, end;
	cin >> begin >> end;
	int n;
	cin >> n;
	vector<string> v(n, "");
	for (int i=0; i < n; i++) {
		cin >> v[i];
	}

	cout << EfficientSolution().ladderLength(begin, end, v);

	return 0;
}