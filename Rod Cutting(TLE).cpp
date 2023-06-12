//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[],int n){
      if(n<=0) return 0;
      int maxi=INT_MIN;
      for(int i=0;i<n;i++){
          maxi=max(maxi,price[i]+solve(price,n-(i+1)));
      }
      return maxi;
  }
    int cutRod(int price[], int n) {
        //code here
        return solve(price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
