//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int solve(vector<int>&prices,int k,int can ,int index,vector<vector<vector<int>>>& dp){
        if(index>= prices.size()) return 0;
        
        if(dp[index][k][can] != -1) return dp[index][k][can];
        if(can==1 && k>0){
            int buy = -prices[index]+ solve(prices,k-1,2,index+1,dp);
            int notBuy = solve(prices,k,1 , index+1,dp);
            return  dp[index][k][can] = max(buy ,notBuy);
        }else if(can==2){
            int sell = prices[index] + solve(prices,k,1,index+1,dp);
            int notSell=solve(prices,k,2,index+1,dp);
        
            return  dp[index][k][can] = max(sell,notSell);
        }
        return 0;
        
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int k = 2;
          vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(3,-1)));
        return solve(prices,k,1,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
