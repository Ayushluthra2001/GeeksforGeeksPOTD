//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int index,int prev){
        if(index >= arr.size()) return 0;
        
        int include = 0;
        if(prev==-1 ||prev+1 != index) include =arr[index] + solve(arr,index+1,index);
        int notInclude = solve(arr,index+1,prev);
        return max(include, notInclude);
        
    }
    int findMaxSum(vector<int>& arr) {
        
        return solve(arr, 0,-1);
        
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
