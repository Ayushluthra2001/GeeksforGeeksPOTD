//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        if(n==1) return {1};
        vector<long long>ans;
        ans.push_back(n);
       
        while(n>1){
            if(n%2==0){
               
                long long val=pow(n,0.5);
                
                long long conv=val;
                ans.push_back(conv);
                n=val;
            }else{
            
                
                long long val=pow(n,1.5);
                 
                long long conv=val;
                 ans.push_back(conv);
                 n=val;
            }
            
            
        }
        //ans.push_back(1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
