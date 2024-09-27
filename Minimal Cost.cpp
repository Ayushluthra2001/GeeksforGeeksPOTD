//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int k , vector<int>& arr , int index, vector<int>& dp){
        if(index >=arr.size()) return -1e5;
        if(index==arr.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        int mini = INT_MAX;
        for(int i = 1;i<=k;i++){
            
           int next = index + i;
           if(next < arr.size()){
               int x =  abs(arr[index+i] - arr[index]) + solve(k, arr, next, dp);
           
               if(x >=0) mini = min(mini , x);
           }
        }
        
        return dp[index] =  mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
         vector<int>dp(arr.size()+1 , -1);
        int x =  solve(k , arr ,0,dp);
        if(x == INT_MAX) return 0;
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
