//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        unordered_map<int,int>mapping;
        for(auto i : arr) mapping[i]++;
        int i = 0;
        while(i< arr.size()){
            int j = i+1;
            while(j < arr.size()){
                if(mapping.find(arr[i]+arr[j]) != mapping.end()) return true;
                j++;
            }
            i++;
        }
        return false;
    }
    
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
