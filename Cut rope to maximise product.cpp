class Solution {
  public:
    int solve(int n,vector<int>&dp){
        if(n ==1) return 1;
        if(n < 0) return 1;
        if(dp[n] != -1) return dp[n];
        int maxi = 0;
        for(int  i=1; i<n; i++){
            maxi = max(maxi ,max( i *(n-i), i*solve(n-i,dp)));
        }
        
        return dp[n]  = maxi;
        
    }
    int maxProduct(int n) {
        // code here
        if(n == 2) return 1;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
