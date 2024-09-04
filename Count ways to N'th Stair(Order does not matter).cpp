//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int n, int lastStep, vector<vector<int>>& dp){
	    if( n==0) return 1;
	    if( n<0) return 0;
	    
	    
	    if(dp[n][lastStep] !=  -1) return dp[n][lastStep];
	    if(lastStep == 0){
	        
	        int one = solve(n-1,1,dp);
	        int two = solve(n-2,2,dp);
	        
	        return dp[n][lastStep] =  one + two ;
	    }else{
	        if(lastStep == 1 ) return dp[n][lastStep] =  solve(n-2,2,dp) + solve(n-1,1,dp);
	        else return dp[n][lastStep] =  solve(n-2,2,dp);
	        
	    }
	    return dp[n][lastStep] =  0;
	}
		int nthStair(int n){
		    //  Code here
		     vector<vector<int>>dp(n+1, vector<int>(3,-1));
		    return solve(n , 0 , dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
