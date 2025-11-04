class Solution {
  public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 0;
        int mini = INT_MAX;
        int x = 1;
        if(dp[n] != -1) return dp[n];
        while(x*x <= n){
            mini = min(mini , 1 +solve(n-(x*x),dp));
            x++;
        }
        
        return dp[n] = mini;
    }
    int minSquares(int n) {
        // Code here
        vector<int>dp(n+1,-1);
        
        return solve( n,dp);
        
        
    }
};
