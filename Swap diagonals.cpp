class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        vector<int>leftDigonal;
        vector<int>rightDigonal;
        for(int i =0; i<mat.size();i++){
            leftDigonal.push_back(mat[i][i]);
        }
        int j = mat.size()-1;
        for(int i =0;i<mat.size();i++){
            rightDigonal.push_back(mat[i][j--]);
            
        }
        j = 0;
        for(int i =0 ;i<mat.size();i++){
            mat[i][i] = rightDigonal[j++];
        }
        j = mat.size()-1;
        int k = 0;
        for(int i =0; i<mat.size();i++){
            mat[i][j--] = leftDigonal[k++];
        }
        
        
    }
};
