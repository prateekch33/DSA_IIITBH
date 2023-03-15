#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &profit, vector<int> &weight, int n, int w, vector<vector<int>> &dp) {
	if(n==0||w==0)
		return 0;
	if(dp[n][w]!=-1)
		return dp[n][w];
	if(weight[n-1]>w)
		return dp[n][w]=knapsack(profit,weight,n-1,w,dp);
	return dp[n][w]=max(profit[n-1]+knapsack(profit,weight,n-1,w-weight[n-1],dp),knapsack(profit,weight,n-1,w,dp));
}

int main() {
	int n,w;
	cin>>n>>w;
	vector<int> profit(n),weight(n);
	for(auto &i:profit) cin>>i;
	for(auto &i:weight) cin>>i;
	vector<vector<int>> dp(n+1, vector<int>(w+1,-1));
	cout<<knapsack(profit,weight,n,w,dp)<<endl;

	return 0;
}