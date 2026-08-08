class Solution {
  public:
    void dfs(int parent, unordered_map<int,vector<int>>&adjencyList,vector<int>&visited){
      
      visited[parent] = true;
      for(auto i : adjencyList[parent]){
          if(!visited[i]){
              dfs(i,adjencyList,visited);
          }
      }
}
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        
        vector<int>visited(n,0);
        int size = edges.size();
          if (size < n - 1) {
            return -1;
        }
        unordered_map<int,vector<int>>adjencyList;
        
        for(int i =0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjencyList[u].push_back(v);
            adjencyList[v].push_back(u);
        }
        
        int count = 0;
        for(int i =0; i<n; i++){
            if(visited[i] == 0){
                dfs(i,adjencyList,visited);
                count++;
            }
        }
        return count -1;
    }
};
