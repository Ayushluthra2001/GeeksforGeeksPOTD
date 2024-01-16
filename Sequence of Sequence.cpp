//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solve(int m, int n){
    if(m == 0 && n == 0) return 1;
    if(m == 1 && n == 0) return 1;
    if(m == 0 && n > 0) return 0;
    if(n == 0) return m > 0;
    int ways = 0;
    // cout<<m<<" "<<n<<endl;
    for(int i = 0;i < m;i++){
     
     ways += solve((m - i)/2, n - 1);
    }
    return ways;
   }
    int numberSequence(int m, int n){
        return solve(m, n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
