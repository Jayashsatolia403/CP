#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());


        vector<int> horizontal, vertical;

        int prev = 0;

        for (int i : hc) {
        	horizontal.push_back(i-prev);
        	prev = i;
        }
        horizontal.push_back(h-prev);

        prev = 0;

        for (int i : vc) {
        	vertical.push_back(i-prev);
        	prev = i;
        }
        vertical.push_back(w-prev);

        int result = 0;

     //    for (int i : vertical) cout << i << " > ";
     //    cout << endl;
    	// for (int i : horizontal) cout << i << " > ";
    	// cout << endl;

        for (int i : vertical) {
        	for (int j : horizontal) {
        		result = max(result, i*j);
        	}
        }

        return result;
    }
};





int main() {
	int h, w, n, m;
	cin >> h >> w >> n >> m;

	vector<int> hc(n), vc(m);

	for (int i=0; i < n; i++) cin >> hc[i];
	for (int i=0; i < m; i++) cin >> vc[i];

	cout << Solution().maxArea(h, w, hc, vc);

	return 0;
}