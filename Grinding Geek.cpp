//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n,int total,vector<int>&cost,int curr,vector<vector<int>>&dp){
        if(curr>=n) return 0;
        int pic=0,notPic=0;
        if(dp[curr][total]!=-1) return dp[curr][total];
        if(total>=cost[curr]){
            int left=total-cost[curr];
            int refund=cost[curr]*0.9;
            int newTotal=left+refund;
            pic=1+solve(n,newTotal,cost,curr+1,dp);
        }
        notPic=solve(n,total,cost,curr+1,dp);
        return dp[curr][total]=max(pic,notPic);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return solve(n,total,cost,0,dp);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
