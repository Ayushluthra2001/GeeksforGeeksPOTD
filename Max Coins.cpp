//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(),ranges.end());
        vector<int> mx(n+1);
        int maxi=-1;
        mx[n]=0;
        for(int i=n-1; i>-1; --i) {
            maxi=max(maxi,ranges[i][2]);
            mx[i]=maxi;
        }
        int ans=-1;
        for(int i=0; i<n; ++i) {
            int sec=ranges[i][1];
            int l=i+1,h=n-1;
            while(l<=h) {
                int m=l+(h-l)/2;
                if(ranges[m][0]<sec) {
                    l=m+1;
                }
                else {
                    h=m-1;
                }
            }
            ans=max(ans,ranges[i][2]+mx[l]);
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
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
