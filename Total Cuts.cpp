//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int>prefix(N,0);
        vector<int>suffix(N,0);
        int maxi=A[0];
        for(int i=0;i<N;i++){
            maxi=max(maxi,A[i]);
            prefix[i]=maxi;
        }
        int mini=A[N-1];
        for(int i=N-1;i>=0;i--){
            mini=min(mini,A[i]);
            suffix[i]=mini;
        }
        int count=0;
        for(int i=0;i<N-1;i++){
            if(prefix[i]+suffix[i+1]>=K)count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
