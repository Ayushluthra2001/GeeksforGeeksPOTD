//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        unordered_map<int,int>mapping;
        int first = arr[0];
        int second = arr[1];
        mapping[second-first]++;
        for(int i = 2; i<arr.size(); i++){
            mapping[arr[i]-second]++;
            second = arr[i];
        }
       // for(auto i : mapping) cout<<i.first<<" "<<i.second<<endl;
        int maxDiff = 0;
        int maxi = 0;
        for(auto i : mapping) if(i.second > maxi) maxDiff= i.first, maxi = i.second;
        int a = arr[0];
        for(int i = 1; i<arr.size();i++){
            if(a + maxDiff  != arr[i]) return a + maxDiff;
            a = arr[i];
        }
        return a + maxDiff;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
