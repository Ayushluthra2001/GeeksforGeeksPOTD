//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int mini = *min_element(arr.begin(),arr.end());
        int maxi = *max_element(arr.begin(),arr.end());
        unordered_map<int,int>mapping;
        for(auto i: arr) mapping[i]++;
        for(int i =1; i<=maxi;i++){
            if(mapping.find(i) == mapping.end()) return i;
        }
        
        return maxi+1 <= 0 ? 1 : maxi+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
