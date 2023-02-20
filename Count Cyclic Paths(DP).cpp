//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{  
public:
    int countPaths(int N){
        // code here
        if(N<=1)
            return 0;
        int mod=1e9+7;
        vector<vector<int>> dp(N+1, vector<int>(2,0));
        dp[2][0]=2;dp[2][1]=3;
        
        if(N==2)
            return dp[N][1];
        
        for(int n=3;n<=N;n++)
        {
            int temp1 = dp[n-1][0]%mod;  
            int temp2 = dp[n-1][1]%mod;
            dp[n][0] = (((2*temp1)%mod)+temp2)%mod;  
            dp[n][1] = (((2*temp1)%mod)+temp1)%mod;
        }
        return dp[N][1];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
