//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<int> search(string& pat, string& txt) {
        // code here
        int n = txt.size(), m = pat.size();
        int pos = 0;
        vector<int> ans;
        
        while(1) {
            size_t ind = txt.find(pat,pos);
            if(ind != std::string::npos) {
                ans.push_back(ind);
                pos = ind+1;
            }
            else {
                break;
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
