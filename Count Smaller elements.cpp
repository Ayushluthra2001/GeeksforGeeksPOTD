//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        
        vector<int>temp = arr;
        //sort(temp.begin(),temp.end());
        int n = arr.size();
        vector<int>ans(n,0);
        for(int i=n-2;i>=0;i--){
            int count =0;
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]) count++;
            }
            ans[i] = count;
        }
        
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
