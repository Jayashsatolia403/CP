#include <bits/stdc++.h>
using namespace std;


// Logic : We can store target - v[i] to a map in O(n) time and O(n) space.
// 		   If any value exists in map return it's index and current index.


int main() {
	int n, target;
	cin >> n >> target;

	vector<int> v(n, 0);


	for (int i=0; i < n; i++) cin >> v[i];

	int result[2] = {-1, -1};

	map<int, int> track;

	for (int i=0; i < n; i++) {
		if (track.count(v[i])) {
			result[0] = track[v[i]];
			result[1] = i;
			break;
		}
		else {
			track[target-v[i]] = i;
		}
	}

	cout << result[0] << " " << result[1];
	return 0;
}

