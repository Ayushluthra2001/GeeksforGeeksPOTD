//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int i, int n ){
	    if(i>=n) return 0;
	    int include,exclude;
	    include=arr[i]+solve(arr,i+2,n);
	    exclude=solve(arr,i+1,n);
	    return max(include,exclude);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    int maxSum=0;
	    maxSum=solve(arr,0,n);
	    return maxSum;
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
