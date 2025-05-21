class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
     
        
        int maxi = m * n;
        vector<int>temp;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i+1)*(j+1) > maxi) break;
                else temp.push_back((i+1)*(j+1));
               
            }
        }
        sort(temp.begin(),temp.end());
        return temp[k-1];
        
        
    }
};
