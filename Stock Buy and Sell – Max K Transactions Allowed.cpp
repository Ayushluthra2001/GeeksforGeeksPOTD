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
    int maxProfit(vector<int>& prices, int k) {
        // code here
        
        
        
        
        //vector<vector<int>>dp(prices.size(),vector<int>(3,-1));
       vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(3,-1)));
        return solve(prices,k,1,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
