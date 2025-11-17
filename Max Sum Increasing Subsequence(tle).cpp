class Solution {
  public:
  
    int solve(vector<int>&nums, int currIndex , int prevIndex, int &maxi ,int sum){
        if(currIndex>= nums.size()){
            return 0;
        }
        if(currIndex == nums.size()-1 && nums[currIndex] > nums[prevIndex])  return nums[currIndex];
        else if(currIndex==nums.size()-1) return 0;
        int take = INT_MIN;
        int notTake = INT_MIN;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            take = nums[currIndex]+solve(nums,currIndex+1, currIndex, maxi ,sum);
        }
        notTake = solve(nums,currIndex+1,prevIndex,maxi , sum);
        return max(notTake , take);
        
    }
    int maxSumIS(vector<int>& arr) {
        int maxi = 0;
        int sum = 0;
        
        return solve(arr, 0, -1 , maxi,sum);
        
        
        
        
    }
};
