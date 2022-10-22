//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void solve(int n , int &ans){
      if(n==0){
          ans+=1;
          return ;
      }
      if(n<0) return ;
      solve(n-1,ans);
      solve(n-2,ans);
  }
    int fillingBucket(int N) {
        int ans=0;
        solve(N,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
