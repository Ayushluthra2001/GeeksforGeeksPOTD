//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  # define mod 1000000007
    int solve(vector<vector<int>>&vis , vector<vector<int>>&grid,int n , int m, int i , int j,vector<vector<int>>&dp){
      if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0 ) return 0;
      if(i==n-1 && j==m-1 && grid[i][j]==1) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
      int down=solve(vis,grid,n,m,i+1,j,dp)%mod;
      int right=solve(vis,grid,n,m,i,j+1,dp)%mod;
      return dp[i][j]=(down+right)%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        if(grid[n-1][m-1]==0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>>vis(n+1,vector<int>(m+1,false));
        
        return solve(vis,grid,n,m,0,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
