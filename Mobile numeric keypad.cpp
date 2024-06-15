//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  unordered_map<int, vector<int>>mp;
  long long dp[11][26];
  long long solve(int n, int last, int i){
      if(i==n-1) return 1; //base case
      
      if(dp[last][i]!=-1)return dp[last][i];
      
     long long ans=0;
     for(auto itr: mp[last]){
         ans+= solve(n, itr, i+1);
     }
     
     return dp[last][i]=ans;
  }
    long long getCount(int n) {
        // Your code goes here
        long long ans=0;
        memset(dp, -1, sizeof(dp));
        
        mp[0]={0, 8};
        mp[1]={1, 2,4};
        mp[2]={1, 2,3, 5};
        mp[3]={6, 2,3};
        mp[4]={1, 4,5, 7};
        mp[5]={2, 4,5, 6, 8};
        mp[6]={3, 5,6, 9};
        mp[7]={7, 4, 8};
        mp[8]={8, 7, 9, 0,5};
        mp[9]={9, 6, 8};
        for(int i=0; i<=9; i++){
            ans+=solve(n, i, 0);
            // cout<<solve(n, i, 0)<<" ";
        }
         return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
