//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int>ans(n,0);
        ans[0]=0;
        unordered_map<int,int>mapping;
        for(int i=1;i<n;i++){
            int k=ans[i-1]-i;
            if( k>0 && !mapping[k]){
               
                ans[i]=ans[i-1]-i;
                 mapping[ans[i]]++;
            }else{
                ans[i]=ans[i-1]+i;
                mapping[ans[i]]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
