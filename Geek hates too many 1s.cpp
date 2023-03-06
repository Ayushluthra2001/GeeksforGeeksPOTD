//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:

    int noConseBits(int n) {

        string s= bitset<64>(n).to_string();

        for(int i = 0;i<s.size()-2;i++){

            if(s[i] == '1'&& s[i+1] == '1' && s[i+2] == '1'){

                s[i+2] = '0';

            }

        }

        int ans = stoi(s, 0, 2);

        return ans;

    }

};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
