//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
int solve(int x ,int y){
    if(x==0 && y==0 ) return 1;
    if(x<0 || y<0) return 0;
    int left=solve(x,y-1);
    int right=solve(x-1,y);
    return left+right;
}
    int ways(int x, int y)
    {
        //code here.
        return solve(x,y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends
