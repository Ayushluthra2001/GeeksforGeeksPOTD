//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    vector<int> Series(int n) {
        // Code here
    int mod=1e9+7;
    vector<int>ans;
    ans.push_back(0);
    ans.push_back(1);
    int a=0;
    int  b=1;
    int  c;
    for(int i=2;i<=n;i++){
        c=((a%mod)+(b%mod))%mod;
        ans.push_back(c%mod);
        a=b%mod;
        b=c%mod;
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
