//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int solve(int start, int end , string str,vector<vector<int>>&dp){
      if(start>end) return 0;
      
      if(dp[start][end] !=-1) return dp[start][end];
      
      if(str[start]==str[end]){
          return dp[start][end]=solve(start+1,end-1,str,dp);
      }else{
          int first = 1 + solve(start+1,end,str,dp);
          int second = 1 + solve (start,end-1,str,dp);
          return dp[start][end]=min(first,second);
      }
      return 0;
  }
    int countMin(string str){
    //complete the function here
            vector<vector<int>>dp(str.length(),vector<int>(str.length(),-1));
         return solve(0,str.length()-1,str,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
