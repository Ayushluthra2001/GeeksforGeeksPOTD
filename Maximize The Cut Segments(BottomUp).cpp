//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    // int solve(int n , int x , int y , int z,vector<int>&dp){
    //     if(n<0) return INT_MIN;
    //     if(n==0) return 0;
        
    //     if(dp[n] != -1) return dp[n];
        
    //     int cut1 = 1 + solve(n-x,x,y,z,dp);
    //     int cut2 = 1 + solve(n-y,x,y,z,dp);
    //     int cut3 = 1 + solve(n-z,x,y,z,dp);
        
    //     return dp[n] = max(cut1 , max(cut2,cut3));
        
    // }
    // int maximizeTheCuts(int n, int x, int y, int z)
    // {
    //     //Your code here
    //     vector<int>dp(n+1,-1);
    //     int ans = solve(n,x,y,z,dp);
        
        
    //      return ans<0 ? 0 :ans  ;
        
        
    // }
    
   
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i=0;i<=n;i++){
                
                if(i >= x) dp[i] = max(dp[i], dp[i - x] + 1);
                if(i >= y) dp[i] = max(dp[i], dp[i - y] + 1);
                if(i >= z) dp[i] = max(dp[i], dp[i - z] + 1);
                
               
                
            
        }
        
        
         return dp[n] < 0  ? 0 : dp[n];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
