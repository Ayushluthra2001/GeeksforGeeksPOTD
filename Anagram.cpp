//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char,int>mapping;
        
        for(auto i : s1) mapping[i]++;
        for(auto i : s2){
            if(mapping.find(i) == mapping.end()) return false;
            else{
                mapping[i]--;
                if(mapping[i] == 0) mapping.erase(i);
            }
        }
        
        return true;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
