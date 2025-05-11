//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int>subarr;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j<arr.size();j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum += arr[k];
                }
                
                subarr.push_back(sum);
            }
        }
        
        
        sort(subarr.begin(),subarr.end());
        // for(auto i : subarr) cout<<i<<" ";
        // cout<<endl;
        if(k  > subarr.size()) return -1;
        return subarr[subarr.size()-k];
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
