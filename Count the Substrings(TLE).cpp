//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int count=0;
        for(int i=0;i<S.length();i++){
            
            for(int j=i;j<S.length();j++){
                 int countLower=0;
                int countUpper=0;
                for(int k=i;k<=j;k++){
                    // cout<<S[k];
                   
                    if(islower(S[k])) countLower++;
                    else countUpper++;
                   
                    
                }
                if(countLower==countUpper) count++;
                //   cout<<countLower<<" "<<countUpper<<endl;
                // cout<<endl;
                
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
