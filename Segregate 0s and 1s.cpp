//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int countZero = 0;
        int countOne  = 0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) countZero++;
            else countOne++;
        }
        int k=0;
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(k<countZero){
                arr[i] =0;
                k++;
                
            }else arr[i] =1 , j++;
        }
        
        
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
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
