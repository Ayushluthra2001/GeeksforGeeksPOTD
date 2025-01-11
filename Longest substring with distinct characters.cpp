//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int longestUniqueSubstr(string &s) {
        // code here
        int i = 0, j = 0;
        unordered_set<char> st;
        int ans = 0;
        while(j < s.size()) {
            if(st.find(s[j]) != st.end()) {
                while(s[i] != s[j]) {
                    st.erase(s[i]);
                    i++;
                }
                i++;
            } else {
                st.insert(s[j]);
            }
            j++;
            ans = max(ans, j - i);
        }
        return ans;
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
