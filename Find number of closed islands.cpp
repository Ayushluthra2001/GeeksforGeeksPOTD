//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int row,int col,vector<vector<int>>& mat)
    {
        mat[row][col] = 0;
        
        if(row < mat.size() - 1  && mat[row+1][col] == 1)
        {
            dfs(row+1,col,mat);
        }
        if(row > 0  && mat[row-1][col] == 1)
        {
            dfs(row-1,col,mat);
        }
        if(col < mat[0].size() - 1  && mat[row][col+1] == 1)
        {
            dfs(row,col+1,mat);
        }
        if(col > 0  && mat[row][col-1] == 1)
        {
            dfs(row,col-1,mat);
        }
        
    }
    
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i == n-1 || i == 0) || (j == m-1 || j == 0))
                {
                    if(mat[i][j] == 1)
                    {
                        dfs(i,j,mat);
                    }
                }
            }
        }
        
        // for(auto x:mat)
        // {
        //     for(auto z:x)
        //     {
        //         cout<<z<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                    dfs(i,j,mat);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
