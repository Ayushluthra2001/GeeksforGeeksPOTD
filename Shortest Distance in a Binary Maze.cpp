//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
         if(source.first==destination.first && source.second==destination.second) return 0;
     queue<pair<int,pair<int,int>>>q;
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>>dist(n,vector<int>(m,1e9));
      dist[source.first][source.second]=0;
       q.push({0, {source.first, source.second}});
    
      vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1}; 
      while(!q.empty()){
         
         auto it = q.front();
          int dis = it.first;
            int r =it.second.first;
            int c = it.second.second;q.pop();
          for(int i=0;i<4;i++){
              int newrow=r+dr[i];
              int newcol=c+dc[i];
                
               if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] and 1 + dis < dist[newrow][newcol]){
                  
                   dist[newrow][newcol] = 1 + dis;
                   if(newrow==destination.first && newcol==destination.second) return 1+dis;
                   q.push({1 + dis, {newrow, newcol}});
                  
                  
              }
          }
      }
       
      return -1 ;
    }
    
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
