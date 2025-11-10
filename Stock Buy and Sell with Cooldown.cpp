class Solution {
  public:
  int solve(int currIndex, int buy ,vector<int>&arr){
      if(currIndex>=arr.size()) return 0;
      int profit = 0;
      if(buy==1){
          
          profit = max(profit , -arr[currIndex] +solve(currIndex+1,0,arr));
          profit = max(profit , solve(currIndex+1,1,arr));
          
      }else{
          profit = max(profit , arr[currIndex] + solve(currIndex+2,1,arr));
          profit = max(profit , solve(currIndex+1,0,arr));
      }
      return profit;
  }
    int maxProfit(vector<int>& arr) {
        // code here
        
        return solve(0, 1,arr);
        
    }
};
