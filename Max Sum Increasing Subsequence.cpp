class Solution {
  public:
  
    int solve(vector<int>&nums, int currIndex , int prevIndex ,vector<vector<int>>&dp){
        if(currIndex>= nums.size()){
            return 0;
        }
        if(currIndex == nums.size()-1 && nums[currIndex] > nums[prevIndex])  return nums[currIndex];
        else if(currIndex==nums.size()-1) return 0;
        
        if(dp[prevIndex+1][currIndex] !=-1) return dp[prevIndex+1][currIndex];
        int take = INT_MIN;
        int notTake = INT_MIN;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            take = nums[currIndex]+solve(nums,currIndex+1, currIndex ,dp);
        }
        notTake = solve(nums,currIndex+1,prevIndex , dp);
        return dp[prevIndex+1][currIndex] = max(notTake , take);
        
    }
    int maxSumIS(vector<int>& arr) {

        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        
        return solve(arr, 0, -1 ,dp);
        
        
        
        
    }
};
