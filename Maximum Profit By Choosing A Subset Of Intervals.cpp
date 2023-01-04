//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int getLowerBound(int ind, vector<vector<int>>& arr) {
        int lb = -1;
        int low = ind+1;
        int high = arr.size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid][0] >= arr[ind][1]) {
                lb = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return lb;
    }
  
    int getMaxProfit(int ind, vector<vector<int>>& arr, vector<int>& dp) {
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int notPick = getMaxProfit(ind+1, arr, dp);
        int nextIdx = getLowerBound(ind, arr);
        
        int pick = arr[ind][2] + (nextIdx == -1 ? 0 : getMaxProfit(nextIdx, arr, dp));
        
        return dp[ind] = max(pick, notPick);
        
    }
    
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int>dp(n, -1);
        return getMaxProfit(0, intervals, dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
