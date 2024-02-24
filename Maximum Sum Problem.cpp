//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int n){
        if(n==0) return 0;
        if(n<=0) return 0;
        //if(n==1) return 1;
     
        int first=solve(n/2);
        int second=solve(n/3);
        int third=solve(n/4);
        // first=max(first,n/2);
        // second=max(second,n/3);
        // third=max(third,n/4);
        return max((first+second+third),n);
        
        return max(first,max(second,third));
    }
        int maxSum(int n)
        {
            //code here.
          
            return solve(n);
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
