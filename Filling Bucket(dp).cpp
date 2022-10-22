//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int  solve(int n , vector<int>& dp){
      if(n==0){
          return 1;
         
      }
      if(n<0) return 0 ;
      if(dp[n]!=-1) return dp[n] ;
      
      dp[n]=(solve(n-1,dp)+solve(n-2,dp))%100000000;
      return dp[n];
  }
    int fillingBucket(int N) {
        
        vector<int>dp(N+1,-1);
        return solve(N,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
