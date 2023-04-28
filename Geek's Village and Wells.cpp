//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &mat){
        // Code here
        // standard graph based bfs problem
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='W'){
                    pq.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dist=0;
        vector<vector<int>> ans(n,vector<int> (m,0)); 
        int delrow[4]={-1,1,0,0};
        int delcol[4]={0,0,-1,1};
        while(!pq.empty()){
            int siz = pq.size();
            while(siz--){
                auto it = pq.front();
                pq.pop();
                int row = it.first;
                int col = it.second;
                if(mat[row][col]=='H'){
                    ans[row][col]=dist;
                }
                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&mat[nrow][ncol]!='N'){
                        vis[nrow][ncol]=1;
                        pq.push({nrow,ncol});
                    }
                }
            }
            dist++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='N'||mat[i][j]=='W'||mat[i][j]=='.'){
                    ans[i][j]=0;
                }
                if(mat[i][j]=='H'){
                    if(ans[i][j]==0){
                        ans[i][j]=-1;
                    }
                    else{
                        ans[i][j]*=2;
                    }
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
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
