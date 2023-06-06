//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int N) {
        // code here
        vector<int>sieve(N+1,1);
        sieve[0]=0;
        for(int i=2;i<=N;i++){
            if(sieve[i]==1){
                for(int j=i*i;j<=N;j+=i){
                    sieve[j]=0;
                }
            }
        }
        // for(int i=0;i<sieve.size();i++){
        //     if(sieve[i]==1){
        //         cout<<i<<" ";
        //     }
        // }
        // cout<<endl;
        vector<int>ans(N+1,0);
        ans[1]=1;
        for(int i=2;i<ans.size();i++){
            for(int j=2;j<sieve.size();j++){
                if(sieve[j]==1 && i%j==0){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
