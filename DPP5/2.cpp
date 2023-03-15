// https://practice.geeksforgeeks.org/problems/edit-distance3702/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int edit(string s,string t, int n,int m, vector<vector<int>> &dp) {
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1])
            return dp[n][m]=edit(s,t,n-1,m-1,dp);
        return dp[n][m]=min({edit(s,t,n-1,m,dp),edit(s,t,n,m-1,dp),edit(s,t,n-1,m-1,dp)})+1;
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return edit(s,t,s.size(),t.size(),dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends