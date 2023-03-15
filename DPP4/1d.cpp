#include<bits/stdc++.h>

using namespace std;

int lcs(string s1,string s2, int n, int m, vector<vector<int>> &dp) {
	if(m==0||n==0)
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s1[n-1]==s2[m-1])
		return dp[n][m]=lcs(s1,s2,n-1,m-1,dp)+1;
	return dp[n][m]=max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
}

int main() {
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size(),m=s2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
	cout<<lcs(s1,s2,n,m,dp)<<endl;

	return 0;
}