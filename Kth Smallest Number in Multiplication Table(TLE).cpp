class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        vector<vector<int>>matrix(m,vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                matrix[i][j] = (i+1)*(j+1);
            }
        }
        
        vector<int>temp;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        return temp[k-1];
    }
};
