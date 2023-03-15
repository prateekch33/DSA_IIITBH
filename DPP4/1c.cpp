#include<bits/stdc++.h>

using namespace std;

int mcm(vector<int> &a,int i,int j, vector<vector<int>> &dp) {
	if(i==j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int ans=INT_MAX,cnt=0;
	for(int k=i;k<j;k++) {
		cnt=mcm(a,i,k,dp)+mcm(a,k+1,j,dp)+a[i-1]*a[k]*a[j];
		ans=min(ans,cnt);
	}
	return dp[i][j]=ans;
}

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i:a) cin>>i;
	vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
	cout<<mcm(a,1,n-1,dp)<<endl;

	return 0;
}