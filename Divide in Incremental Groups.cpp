//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[101][101][101];
    int solve(int i,int cnt,int sum,int n,int k,vector<int>&a){
        if(cnt>k)return 0;
        if(sum>n)return 0;
        if(i>=n){
            if(cnt==k&&sum==n)return 1;
            return 0;
        }
        if(dp[i][cnt][sum]!=-1)return dp[i][cnt][sum];
        int ans=0;
        ans+=solve(i+1,cnt,sum,n,k,a);
        if((sum+a[i])<=n);
        ans+=solve(i,cnt+1,sum+a[i],n,k,a);  
        return dp[i][cnt][sum]=ans;
    }
    int countWaystoDivide(int n,int k) {
        vector<int>a(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)a[i]=i+1;
        return solve(0,0,0,n,k,a);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends
