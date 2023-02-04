//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    vector<int>dp(n+1,0);
	    for(int i=n-1;i>=0;i--){
	       int include,exclude;
	       include=i+2<n ? arr[i]+dp[i+2] : arr[i];
	       exclude=i+1<n ? dp[i+1] : 0;
	       dp[i]=max(include,exclude);
	    }
	    return dp[0];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
