//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int>ans;
        
       
        int start = 0;
        int n = mat.size();
        int m = mat[0].size();
        int startRow = 0 , endRow = n-1, startCol = 0 , endCol = m-1;
        int total = n*m;
    
        while(start <= n*m){
            
            for(int i =startCol; i<=endCol && start< total; i++){
                ans.push_back(mat[startRow][i]);
                start++;
            }
            startRow++;
            if(start >= total) return ans;
            for(int i = startRow; i<=endRow && start <total; i++){
                ans.push_back(mat[i][endCol]);
                start++;
            }
            endCol--;
             if(start >= total) return ans;
            for(int i =endCol; i>=startCol && start<total; i--){
                ans.push_back(mat[endRow][i]);
                start++;
            }
            endRow--;
             if(start >= total) return ans;
            for(int i=endRow;i>=startRow && start<total; i--){
                ans.push_back(mat[i][startCol]);
                start++;
            }
            startCol++;
             if(start >= total) return ans;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
