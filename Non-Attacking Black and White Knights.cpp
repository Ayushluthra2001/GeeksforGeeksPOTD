class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        
        vector<int>da  = {2,2,-2,-2,1,1,-1,-1};
        vector<int>db =  {1,-1,1,-1,2,-2,2,-2};
        int ans = 0;
        
        
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                int count =1;
                for(int d = 0; d<8; d++){
                    int newI = i + da[d];
                    int newJ = j + db[d];
                    if(newI >= 0 && newI < n  && newJ >= 0 && newJ <m){
                        count++;
                    }
                   
                }
                 ans += (n*m) - count;
                
                
            }
        }
        
        return ans;
        
    }
};
