#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
    
const int N=201000;
int n,m,_;


class Solution {
public:
	vector<int> dp;
    vector<int> output;

	bool dfs(vector<int> &nums, int target, int key, vector<int> result) {
		int n = nums.size();

		if (target == 0) {
            output = result;
            return true;
        }
		if (target < 0) return false;

		if (dp[target] != -1) return dp[target];

		if (key >= n) return false;

        dp[target] = dfs(nums, target, key+1, result);
        
        result.pb(nums[key]);
		dp[target] = dp[target] || dfs(nums, target-nums[key], key+1, result);

		return dp[target];
	}

    bool canPartition(vector<int>& nums, int target) {
    	dp = vector<int>(target+1, -1);

        vector<int> result;

    	dfs(nums, target, 0, result);

        cout << output.size() << endl;

        for (int i : output) cout << i << " ";
        cout << endl;

        return true;
    }
};
    
    
int main() {
    int T;
    cin >> T;
    
    rep (t, 1, T+1) {
        int x, y;
        cin >> n >> x >> y;

        int sum = 0;
        rep (i, 1, n+1) sum += i;

        if (sum % (x+y) != 0) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        } 

        cout << "Case #" << t << ": " << "POSSIBLE" << endl;

        int check = (sum / (x+y)) * x;

        vector<int> nums;
        rep (i, 1, n+1) nums.pb(i);

        Solution().canPartition(nums, check);
        
    }
    
    return 0;
}