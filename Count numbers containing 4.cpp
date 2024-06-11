//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int n){
        bool got=false;
        while(n>0){
            if(n%10==4) return true;
            n=n/10;
        }
        return false;
  }
    int countNumberswith4(int n) {
        // code here
        int count=0;
        int i=1;
        while(i<=n){
            count+=solve(i);
            i++;
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
