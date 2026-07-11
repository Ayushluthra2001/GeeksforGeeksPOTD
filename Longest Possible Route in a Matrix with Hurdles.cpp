class Solution {
  public:
    int solve(vector<vector<int>>&mat,int i , int j , int x , int y,
    vector<vector<int>>&visited,int n , int m){
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j]!= -1 || mat[i][j] == 0) return INT_MIN;
        if(i == x && j == y) return 0;
        
        
        int maxi = INT_MIN;
        visited[i][j] = 1;
        int down  = solve(mat,i+1,j,x,y,visited,n,m);
        int right = solve(mat,i,j+1,x,y,visited,n,m);
        int up    = solve(mat,i-1,j,x,y,visited,n,m);
        int left  = solve(mat,i,j-1,x,y,visited,n,m);
        if(down  != INT_MIN) maxi = max(maxi , 1 + down);
        if(right != INT_MIN) maxi = max(maxi , 1 + right);
        if(up    != INT_MIN) maxi = max(maxi , 1 + up);
        if(left  != INT_MIN) maxi = max(maxi , 1 + left);
        visited[i][j] = -1;
        return maxi ;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        if(mat[xd][yd] == 0) return -1;
        if(mat[xs][ys] == 0) return -1;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n, vector<int>(m,-1));
        int ans  = solve(mat,xs,ys,xd,yd,visited,n,m);
        
        return ans == INT_MIN ? -1 : ans;
    }
};
