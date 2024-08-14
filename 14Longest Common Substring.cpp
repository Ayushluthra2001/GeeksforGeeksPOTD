//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
     int solve(string &str1, string &str2, int i, int j, vector<vector<int>>& dp, int &maxi) {
        if (i >= str1.length() || j >= str2.length()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int curr = 0;
        if (str1[i] == str2[j]) {
            curr = 1 + solve(str1, str2, i + 1, j + 1, dp, maxi);
            maxi = max(maxi, curr); 
        }
        
        dp[i][j] = curr; 
        
        
        solve(str1, str2, i, j + 1, dp, maxi);
        solve(str1, str2, i + 1, j, dp, maxi);
        
        return dp[i][j];
    }

    int longestCommonSubstr(string str1, string str2) {
        int maxi = 0;
        vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
        solve(str1, str2, 0, 0, dp, maxi);
        return maxi; 
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
