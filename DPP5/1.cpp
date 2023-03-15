// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int lis(int a[], int indx,int prevIndx,int n,vector<vector<int>> &dp) {
        if(n==indx) return 0;
        if(dp[prevIndx+1][indx]!=-1) return dp[prevIndx+1][indx];
        
        int nt=lis(a,indx+1,prevIndx,n,dp);
        int t=INT_MIN;
        if(prevIndx==-1 or a[prevIndx]<a[indx])
            t=lis(a,indx+1,indx,n,dp)+1;
        return dp[prevIndx+1][indx]=max(nt,t);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       return lis(a,0,-1,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends