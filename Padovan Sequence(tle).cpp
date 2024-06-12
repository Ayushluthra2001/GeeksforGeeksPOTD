//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int solve(int n){
        if(n==0 || n==1 || n==2) return 1;
        return solve(n-2)+solve(n-3);
    }
    int padovanSequence(int n)
    {
       //code here
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
