class Solution {
  public:
    int maxEdgesToAdd(int v, vector<vector<int>>& edges) {
        // code here
        int x = (v*(v-1))/2;
        return x-edges.size();
        
        
    }
};
