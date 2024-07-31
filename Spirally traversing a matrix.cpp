//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n* m;
        int count=0;
        int toprow =0;
        int topcol =0;
        int endcol =m-1;
        int endrow =n-1;
        while(count<total){
            
            
            for(int i=topcol;i<=endcol;i++ ){
                ans.push_back(matrix[toprow][i]);
                count++;
            }
            toprow++;
             if(count>=total) return ans;
            for(int i=toprow;i<=endrow;i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
             if(count>=total) return ans;
            for(int i=endcol;i>=topcol;i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
             if(count>=total) return ans;
            for(int i=endrow;i>=toprow;i--){
                ans.push_back(matrix[i][topcol]);
                count++;
                
            }
            topcol++;
            if(count>=total) return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
