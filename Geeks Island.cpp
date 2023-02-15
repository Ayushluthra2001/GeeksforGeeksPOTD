//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vis[x][y] = 1;
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, -1, 0, +1};
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m) {
                if(vis[nx][ny]==0 && mat[nx][ny]>=mat[x][y]) {
                    dfs(nx, ny, vis, mat);
                }
            }
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
        vector<vector<int>> vis1(N, vector<int>(M));
        vector<vector<int>> vis2(N, vector<int>(M));
        for(int j=0; j<M; j++) {
            if(vis1[0][j]==0) {
                dfs(0, j, vis1, mat);
            }
            if(vis2[N-1][j]==0) {
                dfs(N-1, j, vis2, mat);
            }
        }
        for(int i=0; i<N; i++) {
            if(vis1[i][0]==0) {
                dfs(i, 0, vis1, mat);
            }
            if(vis2[i][M-1]==0) {
                dfs(i, M-1, vis2, mat);
            }
        }
        int ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(vis1[i][j] && vis2[i][j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends
