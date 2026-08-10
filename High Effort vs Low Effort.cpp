class Solution {
  public:
  int solve(vector<int>&h, vector<int>&l , int index,bool pre,vector<vector<int>>&dp){
      if(index >= h.size()) return 0;
      int high = 0;
      if(dp[index][pre] != -1) return dp[index][pre];
      if(pre == false)
       high = h[index] + solve(h,l,index+1,true,dp);
      int low = l[index] + solve(h,l, index+1,true,dp);
      int no = solve(h,l, index+1,false,dp);
      return dp[index][pre] = max(high, max(low, no));
  }
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        vector<vector<int>>dp(h.size(),vector<int>(2,-1));
        
        return solve(h,l,0,0,dp);
        
    }
};
