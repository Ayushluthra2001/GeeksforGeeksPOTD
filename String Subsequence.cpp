//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int mod=1e9+7;
    int fun(int i,int j,int n,int m,string s1,string s2,vector<vector<int>> &dp)
    {
        if(j==m)
        {
            j=0;
            return 1;
        }
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int cnt=0;
        if(s1[i]==s2[j])
        {
            cnt+=(fun(i+1,j+1,n,m,s1,s2,dp)+fun(i+1,j,n,m,s1,s2,dp))%mod;
        }
        else
        {
            cnt+=fun(i+1,j,n,m,s1,s2,dp)%mod;
        }
        return dp[i][j]=cnt%mod;
    }
    int countWays(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,n,m,s1,s2,dp)%mod;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends
