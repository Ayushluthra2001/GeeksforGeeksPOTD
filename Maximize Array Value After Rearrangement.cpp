//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   #define mod 1000000007
    
    int Maximize(vector<int> arr) {
        // Complete the function
        
        int ans = 0;
        
        sort(arr.begin(),arr.end());
        
        for(int i =0;i<arr.size();i++){
            long long int x= ((long long int )arr[i] * (long long int)i) %mod;
            ans = (ans + x) %mod;
            
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends
