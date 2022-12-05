#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int f = c-(a&b);

    cout << f << endl;

    return 0;
}