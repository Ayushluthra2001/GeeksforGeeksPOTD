class Solution {
  public:
  bool isValid( int i , int j , int n , int m,vector<vector<char>>&grid){
      if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='O') return true;
      return false;
  }
  void dfs(vector<vector<char>>&grid , int i , int j , int n , int m){
      grid[i][j]='B';
      if(isValid(i+1,j,n,m,grid)){
          dfs(grid,i+1, j,n,m);
      }
       if(isValid(i,j+1,n,m,grid)){
          dfs(grid,i, j+1,n,m);
      }
       if(isValid(i-1,j,n,m,grid)){
          dfs(grid,i-1, j,n,m);
      }
       if(isValid(i,j-1,n,m,grid)){
          dfs(grid,i, j-1,n,m);
      }
      
  }
    void fill(vector<vector<char>>& grid) {
        // Code heressdm
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            int j = 0;
            if(grid[i][j]=='O'){
                dfs(grid,i,j,n,m);
            
            }
            j = m-1;
            if(grid[i][j]=='O'){
                dfs(grid,i,j,n,m);
            }
            
        }
        for(int j = 0; j<m; j++){
            int i= 0;
            if(grid[i][j]=='O'){
                dfs(grid,i,j,n,m);
            
            }
            i = n-1;
            if(grid[i][j]=='O'){
                dfs(grid,i,j,n,m);
            }
            
        }
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                else if(grid[i][j]=='B') grid[i][j]='O';
            }
        }
        
    }
};
