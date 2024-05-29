//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int n, int x, int y, vector<int> &dp)
    {
        if(n <= 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int a = 0, b = 0, c = 0; 
        if(n >= 1)
            a = !helper(n-1,x,y,dp);
        if(n >= x)    
            b = !helper(n-x,x,y,dp);
        if(n >= y)
            c = !helper(n-y,x,y,dp);
        if(a||b||c)
            return dp[n]=1;
        else
            return dp[n]=0;
    }
    int findWinner(int n, int x, int y) 
    {
       vector<int> dp(n+1,-1);
       return helper(n, x, y, dp); // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends
