//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
         long long ans=0;
        vector<long long>v{1,3,5,7,9};
        while(N)
        {
            int x=N%5;
              if(x == 0) {
                x = 5;
                N--;
            }
            ans=ans*10+v[x-1];
            N/=5;
        }
        long long a=0;
        while(ans)
        {
            int x=ans%10;
            a=a*10+x;
            ans/=10;
        }
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
