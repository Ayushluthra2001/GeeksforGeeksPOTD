//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &digits , int index,vector<int>&dp){
        if(index >= digits.length()) return 1;
        if(digits[index]=='0') return 0;
        if(dp[index] != -1)return dp[index];
        int one = solve(digits,index+1,dp);
        int two = 0;
        if(index!= digits.length()-1 && (digits[index]=='1'  ||
        digits[index] =='2' && digits[index+1]<='6'))
        two = solve(digits, index+2,dp);
        
        return dp[index] = one + two;
        
    }
    int countWays(string &digits) {
        // Code here
        vector<int>dp(digits.length()+1,-1);
        return solve(digits, 0,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
