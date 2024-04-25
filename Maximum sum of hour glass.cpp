//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3 || m<3) return -1;
        int maxi=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int sum=0;
                sum+=mat[i][j];
                if(i+1<n && j+1<m )sum+=mat[i+1][j+1];
                if(j+1<m )sum+=mat[i][j+1];
                if(j+2<m) sum+=mat[i][j+2];
                if(i+2<n )sum+=mat[i+2][j];
                if(i+2 <n && j+1<m)sum+=mat[i+2][j+1];
                if(i+2<n && j+2<m)sum+=mat[i+2][j+2];
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends
