//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
ll mod=1000000007;
class Solution{
    public:
    ll solve(int i,int N,ll sum,vector<ll> &p,vector<vector<ll>> &dp){
        if(i>=N){
            if(sum==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=0;
        if(sum-p[i]>=0){
            ans=solve(i+1,N,sum-p[i],p,dp);
        }
        
        return dp[i][sum]=(ans+solve(i+1,N,sum,p,dp))%mod;
    }
    
    int numOfWays(int n, int x)
    {
        // code here
        vector<ll> p;
        for(ll i=1;pow(i,x)<=n;i++){
            p.push_back(pow(i,x));
        }
        int N=p.size();
        vector<vector<ll>> dp(N,vector<ll> (n+1,-1));
        return solve(0,N,n,p,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends
