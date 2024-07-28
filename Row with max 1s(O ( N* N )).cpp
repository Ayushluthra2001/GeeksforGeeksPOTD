//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int getCurrentRow(vector<int>&row){
      int count =0;
      for(int i=0;i<row.size();i++){
          count += row[i]==1 ? 1 : 0;
      }
      return count;
  }
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int maxi = 0;
        int index =-1;
        
        for(int i=0;i<arr.size();i++){
            int count = getCurrentRow(arr[i]);
            if(maxi < count){
                maxi = count ;
                index = i;
            }
        }
        
        return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
