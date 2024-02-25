//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
   long long int count(long long int n)
    {
        vector<int>v={3,5,10};
        int dp[4][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<4;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<4;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(j>=v[i-1])
                dp[i][j]=dp[i][j-v[i-1]]+dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[3][n];
    	// Your code here
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
