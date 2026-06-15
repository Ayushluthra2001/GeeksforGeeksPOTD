class Solution {
  public:

    int solve(vector<int>& cost, int w, int currIndex, bool buy,vector<vector<vector<int>>>&dp) {

        if (w == 0) return 0;
        if (w < 0) return 1e9;
        if (currIndex == cost.size()) return 1e9;
        
        
        if(dp[buy][w][currIndex] != -1) 
        return dp[buy][w][currIndex];
        
        int chose1 = 1e9, chose2 = 1e9;
        

        int notChose = solve(cost, w, currIndex + 1, buy,dp);

        if (buy && cost[currIndex] != -1) {

            chose1 = cost[currIndex] +
                     solve(cost, w - (currIndex + 1),
                           currIndex + 1, buy,dp);

            chose2 = cost[currIndex] +
                     solve(cost, w - (currIndex + 1),
                           currIndex, buy,dp);

            return dp[buy][w][currIndex] = min(notChose, min(chose1, chose2));
        }

        return dp[buy][w][currIndex] = notChose;
    }

    int minimumCost(vector<int> &cost, int w) {
        
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(w+1,vector<int>(cost.size(),-1)));

        int ans = solve(cost, w, 0, true,dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};
