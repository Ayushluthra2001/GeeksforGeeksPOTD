//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    #define mod 1000000007
    public:
   
    int padovanSequence(int n)
    {
       //code here
       vector<int>dp(n+1,-1);
       dp[0]=1;
       dp[1]=1;
       dp[2]=1;
       for(int i=3;i<=n;i++){
           dp[i]=(dp[i-2]%mod + dp[i-3]%mod)%mod;
       }
       return dp[n];
       
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
