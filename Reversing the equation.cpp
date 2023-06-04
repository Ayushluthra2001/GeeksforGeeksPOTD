//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans="";
            int i=s.length()-1;
            while(i>=0){
                int j=i;
                string temp="";
                while(j>=0 && s[j]-'0'>=0 && s[j]-'0'<=9){
                    temp+=s[j];
                    j--;
                }
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=s[j];
                i=j-1;
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
