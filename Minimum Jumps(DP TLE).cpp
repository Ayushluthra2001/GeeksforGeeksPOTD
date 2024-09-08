//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int solve(int currIndex , vector<int>& arr,vector<int>& dp){
        if(currIndex >=arr.size()-1) return 0;
        
        if(arr[currIndex] == 0) return -1e5;
        if(dp[currIndex] != -1) return dp[currIndex];
        int mini = INT_MAX;
        for(int i =1; i<=arr[currIndex]; i++){
            int x = solve(currIndex + i , arr,dp);
            if(x >= 0){
                mini =  min(mini , x);
                
            }
        }
        
        
        return dp[currIndex] = mini == INT_MAX  ? -1e5  : mini+1;
        
        
    }
    int minJumps(vector<int>& arr) {
        // Your code here
        vector<int>dp(arr.size()+1, -1);
        int ans =  solve(0 , arr,dp);
        
        return ans == -1e5 ? -1 : ans; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
