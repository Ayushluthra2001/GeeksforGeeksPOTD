//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int sumOfAll(int l, int r){
        // code here
        vector<bool>prime(r+1,true);
        for(int i=2;i<=r;i++){
            if(prime[i]){
                for(int j=i*i;j<=r;j+=i){
                    prime[j]=false;
                }    
            }
            
        }
        
       
        int ans=0;
        while(l<=r){
            if(l==1){
                ans++;
                l++;
                 continue;
            }
             int sum=0;
        for(int i=2;i<=l;i++){
            if(prime[i] && l%i==0){
                sum+=i;
            }
        }
        ans+=sum;
        l++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends
