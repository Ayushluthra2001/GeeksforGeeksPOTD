class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int w , vector<int>& wt ,vector<int>& val , int currIndex){
        if(currIndex >= wt.size() || w<=0) return 0;
        
        
        int pic = 0, notPic = 0;
        
        if(w-wt[currIndex] >=0){
            pic = val[currIndex] + solve(w-wt[currIndex] , wt ,val , currIndex + 1);
            
        }
        notPic = solve(w ,wt, val, currIndex + 1);
        
        return max(pic , notPic);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        
        return solve(W, wt , val , 0);
    }
};
