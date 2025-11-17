class Solution {
  public:
  
    void solve(vector<int>&nums, int currIndex , int prevIndex, int &maxi ,int sum){
        if(currIndex>= nums.size()){
            maxi = max(maxi ,sum);
            return ;
        }
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            solve(nums,currIndex+1, currIndex, maxi , sum+nums[currIndex]);
        }
        solve(nums,currIndex+1,prevIndex,maxi , sum);
        
    }
    int maxSumIS(vector<int>& arr) {
        int maxi = 0;
        int sum = 0;
        solve(arr, 0, -1 , maxi, sum);
        
        
        return maxi;
        
    }
};
