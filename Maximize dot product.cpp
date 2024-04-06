//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int solve(int n, int m, int a[],int b[],vector<vector<int>>&dp){
	    if(n<0 || m<0 ) return 0;
	    if(dp[n][m]!=-1) return dp[n][m];
	    int include=a[n]*b[m]+solve(n-1,m-1,a,b,dp);
	    int exclude=(n==m)?0:solve(n-1,m,a,b,dp);
	    return dp[n][m]=max(include,exclude);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>>dp(n,vector<int>(m,-1));
		return solve(n-1,m-1,a,b,dp);
		
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
