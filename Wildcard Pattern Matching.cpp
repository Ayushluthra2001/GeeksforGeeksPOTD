//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    
    bool solve(string pattern , string str  , int i , int j , int n , int m , vector<vector<int>>& dp){
        
        if( i == n && j==m) return true;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(j==m){
            while(i<pattern.length() && pattern[i]=='*') i++;
            return i == n;
        }
        bool ch1 = false; 
        bool ch2  = false;
        bool ch3= false;
        bool ch4 = false;
        bool ch5 = false;
        
        
        if(pattern[i] == '*') {
            ch1 =  solve(pattern,str , i , j+1 , n , m ,dp);
            ch4 = solve(pattern , str, i+1, j+1, n, m,dp);
            ch5 = solve(pattern , str ,i+1, j,n,m ,dp);            
        }
        if(pattern[i] == str[j]) ch2 =    solve(pattern , str, i+1, j+1, n , m ,dp);
        
        if(pattern[i] == '?') ch3= solve(pattern , str, i+1 , j+1 , n, m , dp);
        return dp[i][j] = ch1 || ch2 || ch3 || ch4 || ch5;
    }
    int wildCard(string pattern, string str) {
        
       // if(pattern.length() > str.length()) return false;
       
       vector<vector<int>>dp(pattern.length()+1,  vector<int>(str.length()+1,-1));
        return solve(pattern , str , 0 , 0 , pattern.length() , str.length(),dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
