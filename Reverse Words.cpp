//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string ans = "";
        int i = 0;
        while ( i  < str.length()){
            int j = i;
            string temp = "";
            while(j < str.length() && str[j] !='.' ){
                temp += str[j++];
            }
            //reverse(temp.begin(),temp.end());
            
            ans= temp +'.'+ ans;
            
            i = j+1;
        }
        ans.pop_back();
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
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
