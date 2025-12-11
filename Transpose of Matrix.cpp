class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>>ans;
        for(int i = 0; i<mat.size();i++){
            vector<int>temp;
            for(int j=0;j<mat.size();j++){
                temp.push_back(mat[j][i]);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
