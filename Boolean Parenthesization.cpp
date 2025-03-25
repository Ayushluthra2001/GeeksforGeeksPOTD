//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int solve(int i,int j,int isTrue,string &s, vector<vector<vector<int>>> &dp ){
        if(i>j) return 0;
        
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        long long ways = 0;
        for(int ind=i+1;ind<=j-1;ind+=2 ){
            int lt = solve(i,ind-1,1,s,dp);
            int lf = solve(i,ind-1,0,s,dp);
            int rt = solve(ind+1,j,1,s,dp);
            int rf = solve(ind+1,j,0,s,dp);
            
            if(s[ind]=='&'){
                if(isTrue) ways+=lt*rt;
                else ways+=(lt*rf) + (lf*rt) + (lf*rf);
            }
            else if(s[ind]=='|'){
                if(isTrue) ways+=lt*rt + (lt*rf) + (lf*rt);
                else ways+=(lf*rf);
            }
            else{ //'^'
                if(isTrue) ways+=(lt*rf) + (lf*rt);
                else ways+=(lf*rf) + (lt*rt);
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s) {
       
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,n-1,1,s,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
