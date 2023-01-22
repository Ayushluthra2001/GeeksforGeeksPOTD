//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>st;
        int i=1;
        string ans="";
        st.push(s[0]);
        
        while(i<s.length()){
            if(!st.empty() && s[i]==st.top()){
                i++;
                st.pop();
            }else{
                st.push(s[i]);
                i++;
            }
        }
        if(st.empty()) return "-1";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
