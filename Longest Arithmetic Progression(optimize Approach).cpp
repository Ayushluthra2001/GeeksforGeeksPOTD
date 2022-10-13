//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
       // code here
       vector<vector<int>>dp(1001,vector<int>(10001,0));
       int mx=0;
       for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
               dp[i][A[i]-A[j]] = max(dp[i][A[i]-A[j]] , 1 + dp[j][A[i]-A[j]]);
               mx=max(dp[i][A[i]-A[j]],mx);
           }
       }
       return mx+1;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
