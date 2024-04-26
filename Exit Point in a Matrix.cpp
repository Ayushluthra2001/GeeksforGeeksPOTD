//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
       
        int prevRow=0,prevCol=0;
        int i=0,j=0;
        int currDirection=0;
        
        while(i<n && j<m && i>=0 && j>=0){
            prevRow=i;
            prevCol=j;
            if(matrix[i][j]==0){
                if(currDirection==0){
                    j++;
                }else if(currDirection==1){
                    i++;
                }else if(currDirection==2){
                    j--;
                }else {
                    i--;
                }
            }else{
                matrix[i][j]=0;
                currDirection =(currDirection+1)%4;
                if(currDirection==0){
                    j++;
                }else if(currDirection==1){
                    i++;
                }else if(currDirection==2){
                    j--;
                }else {
                    i--;
                }
            }
        }
        return {prevRow,prevCol};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
