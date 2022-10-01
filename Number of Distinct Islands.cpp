#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(int i,int j, int n,int m){
        if(i>=0 && i<n && j>=0 && j<m ) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&visited,int i, int j,vector<pair<int,int>>&list,int baser,int basec){
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=1;
        list.push_back({i-baser,j-basec});
        int rows[]={-1,0,+1,0};
        int cols[]={0,-1,0,+1};                 
        for(int k=0;k<=3;k++){
            int newrow=i+rows[k];
            int newcol=j+cols[k];
            if(check(newrow,newcol,n,m) && !visited[newrow][newcol] && grid[newrow][newcol]==1){
                dfs(grid,visited,newrow,newcol,list,baser,basec);
            }
        }
       
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>list;
                    dfs(grid,visited,i,j,list,i,j);
                    s.insert(list);
                }
                
            }
        }
        return s.size();
    }
};
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
