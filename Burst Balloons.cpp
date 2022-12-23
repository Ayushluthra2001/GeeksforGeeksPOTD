//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

public:    
    int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];        
        int ans = INT_MIN;

        for(int ind = i; ind <= j; ind++) {
            int cost = (arr[i-1] * arr[ind] * arr[j+1]) + f(i, ind-1, arr, dp) + f(ind+1, j, arr, dp);
            ans = max(ans, cost);
        }       
        return dp[i][j] = ans;
    }
    
    int maxCoins(int n, vector<int> &arr) {

        arr.push_back(1);

        arr.insert(arr.begin(), 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return f(1, n, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
