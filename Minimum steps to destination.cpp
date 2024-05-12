//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int minSteps(int d) {
        d=abs(d);
      int sum=0,steps=0;
      while(sum<d ||  abs(sum-d)%2!=0){
          steps++;
          sum+=steps;
      }
      return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends
