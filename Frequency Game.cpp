//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int>mapping;
        for(int i=0;i<n;i++){
            mapping[arr[i]]++;
        }
        int largest=0;
        int min=INT_MAX;
        
        for(auto i : mapping){
            if(min>=i.second){
                min=i.second;
                largest=max(largest,i.first);
            }    
        }
        return largest;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
