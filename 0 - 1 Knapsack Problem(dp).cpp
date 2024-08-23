//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int w , vector<int>& wt ,vector<int>& val , int currIndex , vector<vector<int>>& dp){
        if(currIndex >= wt.size() || w<=0) return 0;
        
        
        
        if(dp[currIndex][w] != -1) return dp[currIndex][w];
        int pic = 0, notPic = 0;
        
        if(w-wt[currIndex] >=0){
            pic = val[currIndex] + solve(w-wt[currIndex] , wt ,val , currIndex + 1,dp);
            
        }
        notPic = solve(w ,wt, val, currIndex + 1,dp);
        
        return dp[currIndex][w] = max(pic , notPic);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>>dp (wt.size() +1, vector<int>(W+1, -1));
        return solve(W, wt , val , 0 , dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
