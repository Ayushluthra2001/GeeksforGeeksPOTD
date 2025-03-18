//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>& arr, int find ,int currSum, int index,vector<vector<int>>&dp){
        if(index >= arr.size()){
            return currSum == find;
            
        }
        if(currSum == find) return true;
        if(currSum > find) return false;
        if(dp[index][currSum] != -1 ) return dp[index][currSum];
        bool include =solve(arr,find, currSum + arr[index] , index+1,dp);
        bool notInclude = solve(arr,find, currSum, index+1,dp);
        return dp[index][currSum] =( include || notInclude);
    
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
        }
        if(sum %2 != 0) return false; 
        int find = sum / 2;
        vector<vector<int>> dp(arr.size()+1,vector<int>(find+1,-1));
        return solve(arr,find,0,0,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
