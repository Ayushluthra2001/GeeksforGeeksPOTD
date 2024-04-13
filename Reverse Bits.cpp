//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        vector<long long >bit(32,0);
        int i=31;
        while(i>=0 && x>0){
            bit[i]=x%2;
            x=x/2;
            i--;
        }
       
       
        long long  ans=0;
        
       
       
       for(int i=0;i<32;i++){
            long long k=pow(2,i);
            //cout<<bit[i];
           ans+=bit[i]*k;
          
       }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
