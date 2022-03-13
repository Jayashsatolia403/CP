#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t; 

    for (int T=0; T < t; T++) {
    	int n;
    	cin >> n;
    	vector<int> v(n, 0);
    	for (int i=0; i < n; i++) cin >> v[i];


		int result = 0;

		for (int i=0; i < n-1; i++) {
			int min=v[i], idx=i;

			for (int j=i; j < n; j++) {
				if (min > v[j]) {idx = j; min = v[j];}
			}

			reverse(v.begin()+i, v.begin()+idx+1);

			result += idx - i + 1;
		}

		cout << "Case #" << T+1 << ": " << result << endl;
    }

	return 0;
}