//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>freq(arr.size()+1,0);
        for(int i = 0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int repeated = -1;
        int missing = -1;
        for(int i = 1;i<freq.size();i++){
            if(freq[i]==0) missing = i;
            if(freq[i]==2) repeated =i;
        }
        
        return {repeated, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
