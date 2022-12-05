#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	string start, end;
	cin >> start >> end;

	map<string, int> a, d;

	vector<pair<string,string>> my;

	for (int i=0; i < n; i++) {
		int x, m;
		cin >> x >> m;
		string at, dt;

		for (int _=0; _ < m; _++) {
			cin >> at >> dt;

			if (x == 1) my.push_back({at, dt});

			a[at]++;
			d[dt]++;
		}
	}

	int count = 0, mn = INT_MAX;
	set<string> result;

	int hours = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
	int minutes = stoi(end.substr(3,2)) - stoi(start.substr(3,2));
	int seconds = stoi(end.substr(6,2)) - stoi(start.substr(6,2));

	int rng = hours*60*60 + minutes*60 + seconds;

	for (int _=1; _ <= rng; _++) {
		if (a.find(start) != a.end()) {
			count+=a[start];
		}
		if (d.find(start) != d.end()) {
			count-=d[start];
		}

		if (count < mn) {
			mn = count;
			result.clear();
			result.insert(start);
		}
		else if (count == mn) {
			result.insert(start);
		}

		if (start.substr(6,2) == "59") {
            start[6] = '0';
            start[7] = '0';
			if (start.substr(3,2) == "59") {
                start[3] = '0';
                start[4] = '0';
				if (start[1] == '9') {
					start[1] = '0';
					start[0]++;
				}
				else start[1]++;
			}
			else {
				if (start[4] == '9') {
					start[4] = '0';
					start[3]++;
				}
				else {
					start[4]++;
				}
			}
		}
		else {
			if (start[7] == '9') {
				start[7] = '0';
				start[6]++;
			}
			else {
				start[7]++;
			}
		}
	}

    int res_count = 0;

	for (auto &p : my) {
        start = p.first;
        end = p.second;


		int hours = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
        int minutes = stoi(end.substr(3,2)) - stoi(start.substr(3,2));
        int seconds = stoi(end.substr(6,2)) - stoi(start.substr(6,2));

        int rng = hours*60*60 + minutes*60 + seconds;


        for (int _=1; _ <= rng; _++) {
            if (result.find(start) != result.end()) {
                res_count++;
            }


            if (start.substr(6,2) == "59") {
                start[6] = '0';
                start[7] = '0';
                if (start.substr(3,2) == "59") {
                    start[3] = '0';
                    start[4] = '0';
                    if (start[1] == '9') {
                        start[1] = '0';
                        start[0]++;
                    }
                    else start[1]++;
                }
                else {
                    if (start[4] == '9') {
                        start[4] = '0';
                        start[3]++;
                    }
                    else {
                        start[4]++;
                    }
                }
            }
            else {
                if (start[7] == '9') {
                    start[7] = '0';
                    start[6]++;
                }
                else {
                    start[7]++;
                }
            }
        }
	}

    int len= result.size();

    int f = __gcd(res_count, len);

    if (res_count == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << res_count/f << "/" << len/f << endl;

    return 0;
}