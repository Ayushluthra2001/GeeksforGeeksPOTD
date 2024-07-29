//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    void solve(vector<vector<int>>& mat, int i, int j, string temp , vector<vector<int>>visited,int n,vector<string>&ans){
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==0 || visited[i][j]==1) return ;
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        
        visited[i][j] = 1;
        solve(mat,i-1,j,temp+'U',visited,n,ans);
        solve(mat,i+1,j,temp+'D',visited,n,ans);
        solve(mat,i,j-1,temp+'L',visited,n,ans);
        solve(mat,i,j+1,temp+'R',visited,n,ans);
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        
        vector<string>ans;
        
        
        if(mat[0][0]==0) return ans;
        
        int n = mat.size();
        vector<vector<int>>visited(n+1,vector<int>(n+1,0));
        solve(mat,0,0,"",visited,n,ans);
        
        if(ans.size()==0){
            ans.push_back("-1");
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
