//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
    
       
        // code here.
        string temp ="";
        while( n > 1){
            temp += to_string(n%9);
            n/=9;
            
        }
        reverse(temp.begin(),temp.end());
        if(n==1) temp = "1" + temp;
        
        long long ans = stol(temp);
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends
