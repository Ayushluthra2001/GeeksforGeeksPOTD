//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    #define mod 1000000007
public:
    long long solve(int n,long long count,long long curr){
        if(count>n) return 0;
        long long temp=1;
        long long i=1;
        long long x=curr;
        while(i<=count){
            temp=((temp%mod)*(x%mod))%mod;
            x++;
            i++;
        }
        return temp%mod+solve(n,count+1,x)%mod;
    }
    long long sequence(int n){
        // code here
        int count=1;
        int curr=1;
        return solve(n,count,curr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
