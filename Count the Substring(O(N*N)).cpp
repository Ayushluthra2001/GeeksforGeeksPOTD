//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  long long countSubstring(string S){
    // code here
    int count=0;
    for(int i=0;i<S.length();i++){
        int one=0;
        int zero=0;
        string str="";
        for(int j=i;j<S.length();j++){
            if(S[j]=='1')one++;
            else if(S[j]=='0') zero++;
            
            if(one>zero) count++;
        }
    }
    return count;
  }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends
