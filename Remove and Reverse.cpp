//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        string ans="";
        int start=0,end=S.length()-1;
        bool flag=0;
        vector<int>f(26,0);
        for(int i=0;i<S.length();i++){
            f[S[i]-'a']++;
        }
        while(start<=end){
            if(flag==0){
                if(f[S[start]-'a']==1) 
                start++;
                else{
                    f[S[start]-'a']--;
                    S[start]='#';
                    start++;
                    flag=1;
                }
            }else{
                if(f[S[end]-'a']==1) 
                end--;
                else{
                    f[S[end]-'a']--;
                    S[end]='#';
                    end--;
                    flag=0;
                }
            }
        }
        if(flag) reverse(S.begin(),S.end());
        for(int i=0;i<S.length();i++){
            if(S[i]!='#') ans+=S[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
