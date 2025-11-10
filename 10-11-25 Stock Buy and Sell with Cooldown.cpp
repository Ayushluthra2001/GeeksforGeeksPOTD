class Solution {
  public:
  int solve(int currIndex, int buy ,vector<int>&arr,vector<vector<int>>&dp){
      if(currIndex>=arr.size()) return 0;
      int profit = 0;
      if(dp[buy][currIndex]!=-1) return dp[buy][currIndex];
      if(buy==1){
          
          profit = max(profit , -arr[currIndex] +solve(currIndex+1,0,arr,dp));
          profit = max(profit , solve(currIndex+1,1,arr,dp));
          
      }else{
          profit = max(profit , arr[currIndex] + solve(currIndex+2,1,arr,dp));
          profit = max(profit , solve(currIndex+1,0,arr,dp));
      }
      return dp[buy][currIndex] = profit;
  }
    int maxProfit(vector<int>& arr) {
        // code here
        vector<vector<int>>dp(2,vector<int>(arr.size(),-1));
        return solve(0, 1,arr,dp);
        
    }
};
