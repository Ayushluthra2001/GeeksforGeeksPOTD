//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int getCurrentRow(vector<int>&arr){
      int start = 0;
      int end   = arr.size()-1;
      int firstOne = -1;
      while(start <=  end){
        int mid = start + (end- start)/2;
        if(arr[mid]==1){
            firstOne = mid;
            end = mid-1;
        }else if(arr[mid] == 1){
            end = mid-1;
        }else start = mid + 1;
      }
      
      if(firstOne == -1) return 0;
      return arr.size()-firstOne;
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
