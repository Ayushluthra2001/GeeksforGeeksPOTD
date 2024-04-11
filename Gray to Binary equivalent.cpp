//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        vector<int>bit;
        while(n>0){
            bit.push_back(n%2);
            n=n/2;
        }
        reverse(bit.begin(),bit.end());
       
        vector<int>ans(bit.size(),0);
        ans[0]=bit[0];
        for(int i=1;i<bit.size();i++){
            ans[i]=bit[i]^ans[i-1];
        }
        int num=0;
        int p=0;
        for(int i=ans.size()-1;i>=0;i--){
            num=num+ans[i]*pow(2,p);
            p++;
        }
        return num;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends
