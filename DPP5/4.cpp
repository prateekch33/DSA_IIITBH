// https://practice.geeksforgeeks.org/problems/dice-throw5349/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long dice(int m, int n, int x, vector<vector<long long>> &dp) {
        if(n==0 && x==0)
            return 1;
        if(x<0||n==0)
            return 0;
        if(dp[n][x]!=-1)
            return dp[n][x];
        long long ans=0ll;
        for(int i=1;i<=m;i++) {
            ans+=dice(m,n-1,x-i,dp);
        }
        return dp[n][x]=ans;
    }
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return dice(M,N,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends