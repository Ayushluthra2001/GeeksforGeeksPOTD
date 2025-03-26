//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int n;
    set<string>st;
    
    bool solve(int ind, string &s, vector<int>&dp){
        if(ind==n) return 1;
        
        if(dp[ind]!=-1) return dp[ind];
        
        string tmp="";
        
        for(int i=ind; i<n; i++){
            tmp+=s[i];
            if(st.find(tmp)!=st.end()){
                if(solve(i+1, s, dp)){
                    return dp[ind]=1;
                }
            }
        }
        
        return dp[ind]=0;
    }
  
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        n=s.length();
        st.insert(dictionary.begin(), dictionary.end());
        vector<int>dp(n, -1);
        
        return solve(0, s, dp);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
