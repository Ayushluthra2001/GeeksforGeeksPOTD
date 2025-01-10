//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        
        
        vector<int>ans;
        unordered_map<int,int>mapping;
        int i = 0 , j = 0;
        while(j < k){
            mapping[arr[j]]++;
            j++;
        }
        //ans.push_back(mapping.size());
        
        while(j < arr.size()){
            ans.push_back(mapping.size());
            mapping[arr[j]]++;
            mapping[arr[i]]--;
            if(mapping[arr[i]] == 0) mapping.erase(arr[i]);
             i++;
             j++;
        }
        ans.push_back(mapping.size());
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
