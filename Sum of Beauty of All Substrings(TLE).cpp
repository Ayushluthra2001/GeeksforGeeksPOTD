//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans=0;
        for(int i=0;i<s.length();i++){
            map<char,int>mapping;
            
            for(int j=i;j<s.length();j++){
                mapping[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto i :mapping){
                    maxi=max(maxi,i.second);
                    mini=min(mini,i.second);
                }
                ans+=maxi-mini;
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
