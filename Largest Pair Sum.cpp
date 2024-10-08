//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        int secondMaxi = INT_MIN;
        
        
        for(int i = 0; i< arr.size(); i++){
            if(maxi==INT_MIN || maxi < arr[i]){
                secondMaxi = maxi;
                maxi = arr[i];
            }else if(maxi > arr[i] && secondMaxi < arr[i]) secondMaxi = arr[i];
        }

        return maxi + secondMaxi;
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
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
