#include <bits/stdc++.h>
using namespace std;


vector<int> v(100005), seg(4*100005);
int n;


void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = v[low];
        return;
    }

    int mid = (low + high)/2;

    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);

    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}


int query(int idx, int low, int high, int l, int r) {
    if (l >= low && high <= r) {
        return seg[idx];
    }

    if (l > high || r < low) return INT_MIN;

    int mid = (low+high)/2;

    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);

    return max(left, right);
}


int main() {
    cin >> n;
    for (int i=0; i < n; i++) cin >> v[i];

    build(0, 0, n-1);

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        cout << query(0, 0, n-1, x, y) << endl;
    }

    return 0;
}













































// #include <bits/stdc++.h>
// using namespace std;


// vector<int> v(100005), seg(4*100005);


// void build(int idx, int low, int high) {
//     if (low == high) {
//         seg[idx] = v[low];
//         return;
//     }

//     int mid = (low+high)/2;

//     build(2*idx+1, low, mid);
//     build(2*idx+1, mid+1, high);

//     seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
// }


// int query(int idx, int low, int high, int l, int r) {
//     if (low >= l && high <= r) return seg[idx];

//     if (high < l || low > r) return INT_MIN;

//     int mid = (low+high)/2;

//     int left = query(2*idx+1, low, mid, l, r);
//     int right = query(2*idx+2, mid+1, high, l, r);

//     return max(left, right);
// }


// int main() {
//     int n;
//     cin >> n;

//     for (int i=0; i < n; i++) cin >> v[i];

//     build(0,0, n-1);

//     int q;
//     cin >> q;
//     while (q--) {
//         int x, y;
//         cin >> x >> y;

//         query(0, 0, n-1, x, y);
//     }

//     return 0;
// }



























































// // #include <bits/stdc++.h>
// // using namespace std;


// // vector<int> seg(4*1000005);
// // vector<int> v(100005);


// // void build(int idx, int low, int high) {
// //     if (low == high) {
// //         seg[idx] = v[low];
// //         return;
// //     }

// //     int mid = (low+high)/2;

// //     build(2*idx+1, low, mid);
// //     build(2*idx+2, mid+1, high);

// //     seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
// // }


// // int query(int idx, int low, int high, int l, int r) {
// //     if (low >= l && high <= r) return seg[idx];

// //     if (low > r || high < l) return INT_MIN;

// //     int mid = (low+high)/2;
    
// //     int left = query(2*idx+1, low, mid, l, r);
// //     int right = query(2*idx+2, mid+1, high, l, r);

// //     return max(left, right);
// // }



// // int main() {
// //     int n;
// //     cin >> n;

// //     for (int i = 0; i < n; i++) {
// //         cin >> v[i];
// //     }

// //     build(0, 0, n-1);

// //     int q;
// //     cin >> q;

// //     while (q--) {
// //         int l, r;
// //         cin >> l >> r;

// //         cout << query(0, 0, n-1, l, r) << endl;
// //     }

// //     return 0;
// // }