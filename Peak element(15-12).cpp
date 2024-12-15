//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        if(arr.size() == 1) return 0;
        if(arr.size()==2) {
            if(arr[0] > arr[1]) return 0;
            else if(arr[1] > arr[0]) return 1;
        }
        int ans = 0;
        for(int i = 1; i  < arr.size()-1 ; i++){
            if(arr[i] > arr[i+1] && arr[i-1] < arr[i]) return i;
        }
        
        if(arr[arr.size()-2] > arr[arr.size()-1]) return arr.size()-2;
         if(arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;
        
        
    
        
        
        
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
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
