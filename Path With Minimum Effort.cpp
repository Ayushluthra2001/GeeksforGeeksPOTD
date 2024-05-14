//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool check(int r, int c, int currRow, int currCol, vector<vector<bool>> visited){
      if(currRow>=r || currRow<0 || currCol>=c || currCol<0 || visited[currRow][currCol]==true) return true;
      return false;
  }
    void solve(int& mini, int r, int c,vector<vector<int>>& height,
    int currRow, int currCol, int currDiff, vector<vector<bool>>visited ,int prevDiff){
        
        if(check(r,c,currRow,currCol,visited)) return ;
       
        if(currRow==r-1 && currCol==c-1){
            currDiff=max(currDiff,abs(prevDiff-height[currRow][currCol])); 
           // cout<<currDiff<<endl;
            mini=min(mini,currDiff);
            return ;
        }
        
        currDiff=max(currDiff,abs(prevDiff-height[currRow][currCol]));
        visited[currRow][currCol]=true;
        
        solve(mini,r,c,height,currRow+1,currCol,currDiff,visited,height[currRow][currCol]);
        solve(mini,r,c,height,currRow-1,currCol,currDiff,visited,height[currRow][currCol]);
        solve(mini,r,c,height,currRow,currCol+1,currDiff,visited,height[currRow][currCol]);
        solve(mini,r,c,height,currRow,currCol-1,currDiff,visited,height[currRow][currCol]);
        
        return ;
        
    }
    int MinimumEffort(int r, int c, vector<vector<int>> &height) {
        // code here
        
        int mini=INT_MAX;
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        solve(mini,r,c,height,0,0,0,visited,height[0][0]);
        
        
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
