class Solution {
  public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0, ntake=0;
        if(s[i]==t[j]){
            take=1+solve(i-1, j-1, s, t, dp);
        }
        ntake=max(solve(i-1, j, s, t, dp), solve(i, j-1, s, t, dp));
        return dp[i][j]=max(take, ntake);
    }
  
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return n+m-solve(n-1, m-1, s1, s2, dp);
    }
};
