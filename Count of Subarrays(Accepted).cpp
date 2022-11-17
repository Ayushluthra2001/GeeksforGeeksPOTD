//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll count=0;
	    int recent=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>k){
	            count++;
	            int left=i-(recent+1);
	            int right = n-i-1;
	            count+=left;
	            count+=right;
	            count+=(left*right);
	            recent=i;
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
