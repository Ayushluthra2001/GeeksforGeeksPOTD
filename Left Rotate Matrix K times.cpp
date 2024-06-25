//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  vector<int>solve(int k , vector<int> temp){
      vector<int>ans(temp.size(),0);
      k= k % temp.size();
      int b= temp.size();
      for(int i=0;i<temp.size();i++){
          ans[(abs(i-k+b))%temp.size()]=temp[i];
      }
      
      return ans;
      
  }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
       
        
       
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            ans[i]=solve(k,mat[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends
