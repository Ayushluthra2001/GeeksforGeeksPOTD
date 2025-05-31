class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        
        int n = matrix.size();
        priority_queue<int>pq;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }else{
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
            }
        }
        
       
        return pq.top();
    }
};
