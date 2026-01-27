class Solution {
    
    bool solve(int r , int c , vector<vector<char>>&mat, int i , string word
    ,vector<vector<bool>>&visited){
        
        
        if(r>=mat.size() || c>=mat[0].size() || r<0 || c<0 || visited[r][c]==true || word[i] != mat[r][c]) return false;
        if(i==word.length()-1){
            return word[i]==mat[r][c];
        }
        
        visited[r][c] = true;
        bool left = solve(r,c-1,mat,i+1,word,visited);
        bool right = solve(r,c+1,mat,i+1,word,visited);
        bool up = solve(r-1,c,mat,i+1,word,visited);
        bool down = solve(r+1,c,mat,i+1,word,visited);
        visited[r][c] = false;
        return (left || right || up || down);
        
        
        
    }
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),0));
        
        for(int i = 0; i<mat.size();i++){
            for(int j = 0; j<mat[0].size();j++){
                if(solve(i, j , mat,0 , word,visited))   return true;
            }
        }
        
        return false;
    }
};
