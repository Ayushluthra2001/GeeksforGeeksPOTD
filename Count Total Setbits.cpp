//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    long long solve(long long x){
        
        long long sum=(x*1ll * pow(2,x-1)*1ll) + 1 ;
        return sum;
    }
  public:
    long long countBits(long long n) {
        // code here
        long long sum=0;
        while(n){
        long long x = log2(n);
        if(sum!=0) sum+=n;
        sum += solve(x);
         n = n - pow(2,x) ;
        //  cout<<n<<endl;
        
        }
        
        return sum;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
