//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  

 
    int countSubstring(string &s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        int count = 0;
        for (auto f : freq) {
            count += f.second + (f.second * (f.second - 1)) / 2;
        }

        return count;
    }
};




//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
