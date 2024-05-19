//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int maxi=0;
        int minDiff=INT_MAX;
        for(int i=0;i<n;i++){
            if(minDiff>abs(k-arr[i])){
                minDiff=abs(k-arr[i]);
                maxi=arr[i];
            }else if(minDiff==abs(k-arr[i])){
                maxi=max(maxi,arr[i]);
            }
        }
        return maxi;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
