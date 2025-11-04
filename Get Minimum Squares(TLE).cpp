class Solution {
  public:
    int solve(int n){
        if(n==0) return 0;
        int mini = INT_MAX;
        int x = 1;
        while(x*x <= n){
            mini =min(mini , 1 +solve(n-(x*x)));
            x++;
        }
        
        return mini;
    }
    int minSquares(int n) {
        // Code here
        
        
        return solve( n);
        
        
    }
};
