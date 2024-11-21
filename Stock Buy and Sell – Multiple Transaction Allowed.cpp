//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int solve(vector<int>& prices , int index , int buy ,vector<vector<int>>& dp){
        
    //     if(index >= prices.size()) return 0 ;
       
    //     if(dp[index][buy+1] != -1) return dp[index][buy+1];
    //     if(buy==-1){
    //         int buying = solve(prices, index+1, index,dp);
    //         int notBuying = solve(prices,index+1, buy,dp);
    //         return dp[index][buy+1] =  max(buying , notBuying);
    //     }else{
    //         int profit = prices[index] - prices[buy];
            
    //         int sellingandBuyingAgain = profit + solve(prices,index+1, index,dp);
    //         int sellingOnly = profit + solve(prices, index+1, -1,dp);
    //         int notSelling = solve(prices , index+1, buy,dp);
            
            
    //         return dp[index][buy+1] = max(sellingandBuyingAgain , max(sellingOnly , notSelling));
            
    //     }
        
    //     return -1 ;
    // }
    int maximumProfit(vector<int>& prices) {
    int n = prices.size();

    // Use two 1D arrays to track the current and next states.
    vector<int> next(n + 1, 0), current(n + 1, 0);

    // Iterate backward over the days.
    for (int index = n - 1; index >= 0; --index) {
        for (int buy = n - 1; buy >= -1; --buy) {
            if (buy == -1) {
                // Calculate profit for not holding stock.
                int buying = (index + 1 < n) ? next[index + 1] : 0;
                int notBuying = (index + 1 < n) ? next[buy + 1] : 0;
                current[buy + 1] = max(buying, notBuying);
            } else {
                // Calculate profit for holding stock.
                int profit = prices[index] - prices[buy];
                int sellingAndBuyingAgain = (index + 1 < n) ? profit + next[index + 1] : profit;
                int sellingOnly = (index + 1 < n) ? profit + next[0] : profit;
                int notSelling = (index + 1 < n) ? next[buy + 1] : 0;
                current[buy + 1] = max(sellingAndBuyingAgain, max(sellingOnly, notSelling));
            }
        }

        // Update `next` for the next iteration.
        next = current;
    }

    return next[0];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
