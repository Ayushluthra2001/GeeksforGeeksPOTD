//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int i = 1;
        int increment = 0;
        while(i < arr.size()){
            if(arr[i]<=arr[i-1]){
                int maxi = abs(arr[i] - arr[i-1]);
                increment += maxi + 1;
                arr[i] +=maxi + 1;
                i++;
            }else{
                i++;
            }
        }
        
        return increment;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
