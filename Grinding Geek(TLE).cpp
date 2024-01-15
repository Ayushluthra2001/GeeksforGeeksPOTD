//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n,int total,vector<int>&cost,int curr){
        if(curr>=n) return 0;
        int pic=0,notPic=0;
        if(total>=cost[curr]){
            int left=total-cost[curr];
            int refund=cost[curr]*0.9;
            int newTotal=left+refund;
            pic=1+solve(n,newTotal,cost,curr+1);
        }
        notPic=solve(n,total,cost,curr+1);
        return max(pic,notPic);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        return solve(n,total,cost,0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
