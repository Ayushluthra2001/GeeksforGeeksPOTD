//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool solve(vector<int>& arr , int sum , int currSum , int index){
        if(sum == currSum) return true;
        if(index >= arr.size()) return false;
        if(currSum > sum) return false;
        
        return (solve(arr, sum, currSum + arr[index], index+1 ) || 
        solve(arr,sum, currSum, index+1));
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return solve(arr,sum,0 , 0);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
