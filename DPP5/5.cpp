// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    
    long long game(int arr[], int i, int j,vector<vector<long long>> &dp) {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long x=(long long)arr[i]+min(game(arr,i+1,j-1,dp),game(arr,i+2,j,dp));
        long long y=(long long)arr[j]+min(game(arr,i+1,j-1,dp),game(arr,i,j-2,dp));
        return dp[i][j]=max(x,y);
    }
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        return game(arr,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends