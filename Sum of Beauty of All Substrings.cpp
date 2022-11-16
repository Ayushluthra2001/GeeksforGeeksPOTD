//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
    int beautySum(string s) {

        // Your code goes here

      

        int n=s.size();

        int ans=0;

        for(int i=0;i<n;i++)

        {

              vector<int>cnt(26,0);

              for(int j=i;j<n;j++)

              {

                  cnt[s[j]-'a']++;

              int maxi=INT_MIN,mini=INT_MAX;

              for(int k=0;k<26;k++)

              {

                  if(cnt[k]>0)

                  mini=min(mini,cnt[k]);

                  maxi=max(maxi,cnt[k]);

              }

             // cout<<mini<<" "<<maxi<<"\n";

              ans+=(maxi-mini);

              }

              

            

        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
