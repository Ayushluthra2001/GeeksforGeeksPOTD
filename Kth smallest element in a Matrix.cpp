class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int>pq;
            
        for(int i = 0; i<mat.size();i++){
            for(int j =0; j<mat[0].size();j++){
                if(pq.size()>=k){
                    pq.push(mat[i][j]);
                    pq.pop();
                }else{
                    pq.push(mat[i][j]);
                }    
            }
        }
        
        return pq.top();
    }
    
};
