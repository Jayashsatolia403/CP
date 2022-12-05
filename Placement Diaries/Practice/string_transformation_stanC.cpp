#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001],mod=1e9+7;

int calculateShift(string src, string target){
	int cnt=0,n=src.length();
	while(cnt<n){
		if(src==target) return cnt;
		++cnt;
		src.insert(src.begin(),src.back());
		src.pop_back();
	}
	return -1;
}

int solve(string src, string target, int k){
	if(src.length()!=target.length()) return 0;
	int shift=calculateShift(src, target), n=src.length();
	if(shift==-1) return 0;
	for(int i=0;i<=k;++i){
		for(int j=0;j<n;++j){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=k;++i){
		int sum=0;
		for(int j=0;j<n;++j){
			sum=(sum+dp[i-1][j])%mod;
		}
		for(int j=0;j<n;++j){
			dp[i][j]=(((sum-dp[i-1][j])%mod)+mod)%mod;
		}
	}
	return dp[k][shift];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string src, target;
	int k;
	cin>>src>>target>>k;
	cout<<solve(src, target, k);
}