#include<bits/stdc++.h>

using namespace std;

bool isPalin(string s, int i,int j) {
	while(i<j) {
		if(s[i++]!=s[j--])
			return 0;
	}
	return 1;
}

int palindromic_partioning(string s,int start,int n,vector<vector<int>> &dp) {
	if(start>=n)
		return 1;
	if(dp[start][n]!=-1)
		return dp[start][n];
	if(isPalin(s,start,n))
		return dp[start][n]=1;
	else {
		int ans=INT_MAX,x=0,y=0;
		for(int i=start;i<n;i++) {
			if(dp[start][i]!=-1)
				x=dp[start][i];
			else
				x=palindromic_partioning(s,start,i,dp);
			if(dp[i+1][start]!=-1) {
				y=dp[i+1][n];
			}
			else
				y=palindromic_partioning(s,i+1,n,dp);
			ans=min(ans,x+y);
		}
		return dp[start][n]=ans;
		
	}
}

int main() {
	string s;
	cin>>s;
	vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
	cout<<palindromic_partioning(s,0,s.size()-1,dp)<<endl;

	return 0;
}