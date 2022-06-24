#include <bits/stdc++.h>
using namespace std;


void print_map(map<char,int> m) {

	for (auto&it : m) {
		cout << "{ ";
		cout << it.first << " : " << it.second << ", ";
		cout << " }";
	}

	cout << endl;
}


int main() {
	string s, p;
	cin >> s >> p;

	map<char, int> m;

	for (char c : p) {
		m[c]++;
	}

	int idx=0, result = 0, count = p.size();

	for (int i=0; i < s.size(); i++) {
		cout << count << " > ";
		print_map(m);

		if (m.count(s[i]) && m[s[i]] > 0) {
			count--;
		}
		else if (count == p.size()) idx++;

		if (m.count(s[i])) m[s[i]]--;

		if (count == 0) {
			result = max(result, i-idx+1);

			m[s[idx++]]++;
			count++;

			// while (!m.count(s[idx]) || m[s[idx]] < 0) {
			// 	idx++;

			// 	if (m[s[idx]] < 0) m[s[idx]]++;
			// }
		}
	}

	cout << count << " > ";
	print_map(m);

	cout << result << endl;

	return 0;
}