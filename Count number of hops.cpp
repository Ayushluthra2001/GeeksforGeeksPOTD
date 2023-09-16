//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long solve(int n,int curr,vector<long long>&dp){
        if(curr==n) return 1;
        if(curr>n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        long  first =solve(n,curr+1,dp)%1000000007;
        long second =solve(n,curr+2,dp)%1000000007;
        long third =solve(n,curr+3,dp)%1000000007;
        return dp[curr]=(first+second+third)%1000000007;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long>dp(n+1,-1);
        return solve(n,0,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
