//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        int red=0,blue=0,green=0;
        for(int i=0;i<n;i++){
            if(a[i]=='R') red++;
            else if(a[i]=='B') blue++;
            else green++;
        }
        if(red==n || blue==n || green==n) return n;
        if((red%2==0&&green%2==0&&blue%2==0)||(red%2==1&&green%2==1&&blue%2==1))
       return 2;

       else return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
