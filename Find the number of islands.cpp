//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void mark(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        if(i < 0 or i >= n or j < 0 or j >= m)
            return;
            
        if(grid[i][j] == 'L')
        {
            grid[i][j] = 'W';
            
            mark(grid, i+1, j, n, m);
            mark(grid, i, j+1, n, m);
            mark(grid, i-1, j, n, m);
            mark(grid, i, j-1, n, m);
            mark(grid, i+1, j+1, n, m);
            mark(grid, i+1, j-1, n, m);
            mark(grid, i-1, j+1, n, m);
            mark(grid, i-1, j-1, n, m);
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 'L')
                {
                    cnt++;
                    mark(grid, i, j, n, m);
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
