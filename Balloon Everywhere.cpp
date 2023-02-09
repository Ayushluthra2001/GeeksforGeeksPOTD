//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int>temp1(26,0);
        vector<int>temp2(26,0);
        string temp="balloon";
        for(auto i : temp){
            temp1[i-'a']++;
        }
        int maxi=INT_MIN;
        int res=INT_MAX;
        for(auto i : s){
            temp2[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(temp1[i]>temp2[i]) return 0;
            else if(temp1[i]!=0 && temp2[i]!=0){
                
                int one=temp2[i]/temp1[i];
                
                maxi=max(maxi,one);
                res=min(res,one);
            }else if(temp1[i]!=0 && temp2[i]==0) return 0;
        }
        
        
        return min(res,maxi);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
