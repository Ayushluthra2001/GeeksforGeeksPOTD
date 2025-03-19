//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&prices,int k,bool can ,int index){
        if(index>= prices.size()) return 0;
        
        if(!can && k>0){
            int buy = -prices[index]+ solve(prices,k-1,!can,index+1);
            int notBuy = solve(prices,k,can , index+1);
            return max(buy ,notBuy);
        }else if(can){
            int sell = prices[index] + solve(prices,k,!can,index+1);
            int notSell=solve(prices,k,can,index+1);
        
            return max(sell,notSell);
        }
        return 0;
        
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        
        
        
        
        
        return solve(prices,k,false,0);
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
