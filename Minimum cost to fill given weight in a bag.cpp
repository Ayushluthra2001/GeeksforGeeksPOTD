//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  int solve(int n , int w, vector<int>&cost ,int currIndex,vector<vector<int>>&dp){
        if(w==0) return 0;
      if(currIndex>=n ||currIndex+1>w) return 1e9;
      
      
        if(dp[currIndex][w]!=-1) return dp[currIndex][w];
      int buy=0;
      int notbuy=0;
      if(cost[currIndex]!=-1 && currIndex+1<=w)
      buy=cost[currIndex]+solve(n,w-(currIndex+1),cost,currIndex,dp);
      notbuy=solve(n,w,cost,currIndex+1,dp);
     return dp[currIndex][w]=min(buy,notbuy);
      
  }
    int minimumCost(int n, int w, vector<int> &cost) {
       // return 0;
        // code here
        
        vector<vector<int>>dp(cost.size()+1,vector<int>(w+1,-1));
        int ans=solve(n,w,cost,0,dp);
        return ans>=1e9 ? -1 :ans ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends
