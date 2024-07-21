//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9+7;
    long long int findMaxProduct(vector<int>& arr) {
        long long int p=1;
        long long int zerocount = 0, negativecount=0;
        long long int maxin = INT_MIN;
        if(arr.size()==1) return arr[0];
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == 0) {
                zerocount++;
                continue;
            }
            if(arr[i]<0) {
                negativecount++;
                maxin = max(maxin, (long long int)arr[i]);
            }
            p = ((p)%mod * arr[i]) % mod;
        }
        if(zerocount == arr.size()) return 0;
        if(negativecount == 1 && zerocount + negativecount == arr.size()) return 0;
        if(negativecount & 1) {
            p /= maxin;
        }
        return p%mod;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
