//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();

        int maxProduct = arr[0]; 
        int currentMax = arr[0]; 
        int currentMin = arr[0]; 

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                swap(currentMax, currentMin);
            }

            currentMax = max(arr[i], currentMax * arr[i]);
            currentMin = min(arr[i], currentMin * arr[i]);

            maxProduct = max(maxProduct, currentMax);
        }

        return maxProduct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
