//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

  //vector<vector<int>>dp
class Solution {
  public:
  #define mod 10000000007
  
void solve(vector<int>& arr, int currIndex,long long int curr, long long int& maxi){
        if(currIndex >= arr.size()){
            maxi = max(maxi , curr);
            return ;
        }
         
      solve(arr,currIndex+1,curr,maxi);
      curr = (curr * (long long)arr[currIndex])%mod;
      solve(arr,currIndex+1,curr,maxi);
        
       
    }
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        
        long long int  maxi = INT_MIN;
      
         solve(arr,0,1,maxi);
        return maxi;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
