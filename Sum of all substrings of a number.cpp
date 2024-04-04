//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    
    public:
    //Function to find sum of all possible substrings of the given string.
     long long sumSubstrings(string s){
        
        
        long long mod=1e9 +7,curr=0,ans=0,prev=0;
        for(int i=0;i<s.length();i++){
            int num=s[i]-'0';
           curr=(prev*10)%mod + (num*(i+1))%mod;
           ans=(ans+curr)%mod;
           prev=curr;
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
