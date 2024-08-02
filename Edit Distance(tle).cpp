//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(string str1, string str2,int n , int m){
      if(n<0 || m<0){
          if(n<0) return m+1;
          if(m<0) return n+1;
            
          
      }
      
      if(str1[n] == str2[m]){
          return 0 + solve(str1,str2,n-1,m-1);
      }else if(str1[n] != str2[m]){
          int insert  = 1 + solve(str1,str2,n,m-1);
          int replace = 1 + solve(str1,str2,n-1,m-1);
          int remove  = 1 + solve(str1,str2,n-1,m);
          
          return min(insert,min(replace,remove));
      }
      return 0;
  }
    int editDistance(string str1, string str2) {
        // Code here
            int n = str1.length()-1;
            int m = str2.length()-1;
            return solve(str1,str2,n,m);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
