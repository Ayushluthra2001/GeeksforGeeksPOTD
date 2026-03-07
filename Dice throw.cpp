class Solution {
  public:
    int solve(int n , int m , int x,vector<vector<vector<int>>>&dp){
        
        if(n==0 && x==0){
            return 1;
        }else if(n==0 && x!=0) return 0;
        if(x < 0 ) return 0;
        if(dp[n][m][x] != -1) return dp[n][m][x];
        int ways = 0;
        for(int f = 1; f<=m; f++){
            ways += solve(n-1, m , x-f,dp);
        }
        return dp[n][m][x] = ways;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(x+1,-1)));
        return solve(n , m , x,dp);
        
    }
};
