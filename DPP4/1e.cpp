#include<bits/stdc++.h>

using namespace std;

int eggDrop(int n,int k, vector<vector<int>> &dp) {
	if(k==1||k==0||n==1)
		return k;
	if(dp[n][k]!=-1)
		return dp[n][k];
	int ans=INT_MAX;
	for(int i=1;i<=k;i++) {
		ans=min(ans,max(eggDrop(n-1,i-1,dp),eggDrop(n,k-i,dp)));
	}
	return dp[n][k]=ans+1;
}

int main() {
	int n,k;
	cin>>n>>k;
	vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
	cout<<eggDrop(n,k,dp)<<endl;

	return 0;
}