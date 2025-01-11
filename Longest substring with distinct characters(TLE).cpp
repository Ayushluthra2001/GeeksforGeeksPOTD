//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(string temp){
      unordered_map<char,int>mapping;
      for(int i = 0; i<temp.length(); i++) mapping[temp[i]]++;
      if(mapping.size() == temp.length()) return true;
      return false;
  }
    int longestUniqueSubstr(string &s) {
        // code here
        int maxi = 0;
        
        for(int i = 0; i<s.length(); i++){
            for(int j = i; j<s.length();j++){
                string temp = "";
                for(int k = i;k<=j; k++){
                    temp+=s[k];
                }
                if(check(temp)) maxi = max(maxi , (int)temp.length());
            }
        }
        
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
