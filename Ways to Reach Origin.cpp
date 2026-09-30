class Solution {
  public:
  int mod = 1e9+7;
    int solve(int x , int y,vector<vector<int>>&dp){
        if(x== 0 && y == 0) return 1;
        if(x<0 || y<0) return INT_MIN;
        if(dp[x][y] !=-1) return dp[x][y];
        int left = solve(x-1,y,dp);
        int down = solve(x,y-1,dp);
        if(left==INT_MIN) left =0;
        if(down ==INT_MIN) down =0;
        return dp[x][y] = (left + down)%mod;
    }
    int ways(int x, int y) {
        // code herel
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return solve(x,y,dp);
        
        
        
        
        
        
        
    }
};
