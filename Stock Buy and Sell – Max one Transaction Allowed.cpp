//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0;
        int buy  = prices[0];
        int sell = prices[0];
        for(int i = 0; i<prices.size(); i++){
            if(buy > prices[i]){
                maxProfit = max(maxProfit , sell - buy);
                sell = prices[i];
                buy = prices[i];
            }else if(sell < prices[i]){
                 sell = prices[i];   
            }
        }
        
        maxProfit = max(maxProfit , sell - buy);
        return maxProfit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
