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
    bool ans=false;
    int solve(int n , int k , int target,vector<int>&coins,int curr,int c,vector<vector<int>>&dp){
        if(curr>target || c>k) return INT_MIN;
        if(curr==target && c!=k) return INT_MIN;
        if(curr!=target && c==k) return INT_MIN;
        if(curr==target && c==k){
            ans=true;
            return 1;
        };
        if(dp[curr][c]!=-1) return dp[curr][c];
        int count=0;
        for(int i=0;i<coins.size();i++){
            int get=solve(n,k,target,coins,curr+coins[i],c+1,dp);
            if(get!=INT_MIN) count+=get;
            
        }
        return dp[curr][c]=count;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>>dp(target+1,vector<int>(K+1,-1));
        solve(N,K,target,coins,0,0,dp);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
