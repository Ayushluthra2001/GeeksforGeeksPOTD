//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(string str1 , string str2 ,  int i , int j, vector<vector<int>>&dp){
	    if(i == str1.length() || j==str2.length()) return 0;
	    
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    if(str1[i] == str2[j] ) {
	        return dp[i][j] = 1  + solve(str1,str2,i+1,j+1,dp);
	    }else{
	        
	        
	        return  dp[i][j] = max(solve(str1,str2,i+1,j, dp) , solve(str1,str2,i,j+1 ,dp));
	    }
	    
	    return 0;
	    
	    
	    
	    
	    
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    vector<vector<int>>dp (n , vector<int>(m, -1));
	    
	    int ls  = solve(str1,str2,0 ,0,dp);
	    int needed = str2.length();
	    int extraNeeded = needed - ls ;
	    int curr = str1.length() - ls + extraNeeded;
	    
	    return  curr;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
