//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int n, string str, vector<int>&  dp ){
	    if( n==0) return 1;
	    if( n<0) return 0;
	    
	    
	    //if(dp[n] !=  -1) return dp[n];
	    if(str.length()==0){
	        
	        int one = solve(n-1,str+'1',dp);
	        int two = solve(n-2,str+'2',dp);
	        
	        return dp[n] =  one + two ;
	    }else{
	        if(str[str.length()-1]-'0' == 1 ) return dp[n] =  solve(n-2,str+'2',dp) + solve(n-1,str+'1',dp);
	        else return dp[n] =  solve(n-2,str+'2',dp);
	        
	    }
	    return 0;
	}
		int nthStair(int n){
		    //  Code here
		     vector<int>dp(n+1,-1);
		    return solve(n , "" , dp);
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
