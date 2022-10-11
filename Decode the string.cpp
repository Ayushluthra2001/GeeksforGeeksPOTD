//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        int n=s.size();
    string ans="";
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]==']')
        {
            while(st.size()>0 && st.top()!='[')
            {
                ans=st.top()+ans;
                st.pop();
            }
            if(st.size()!=0)
            {
                st.pop();
            }
            string num="";
            while(st.size()>0 && st.top()>='0' && st.top()<='9')
            {
                num=st.top()+num;
                st.pop();
            }
            int di=stoi(num);
            string temp=ans;
            for(int i=0;i<di-1;i++)
            {
                ans+=temp;
                
            }
            for(int i=0;i<ans.size();i++)
            {
                st.push(ans[i]);
            }
            ans="";
        }
        else
        {
            st.push(s[i]);
        }
    }
    while(st.size()>0)
    {
        ans=st.top()+ans;
        st.pop();
    }
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
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
