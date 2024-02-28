//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        string temp="";
        int f=0;
        for(int i=s.length()-1;i>=0 && f<=3 ;i--){
           // cout<<s[i]<<endl;
            temp+=s[i];
            f++;
        }
       // cout<<temp<<endl;
        reverse(temp.begin(),temp.end());
        int t=0;
        if(temp.length()>=1)
         t=stoi(temp);
       // return 0;
        return t%8==0 ? 1 : -1;
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
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
