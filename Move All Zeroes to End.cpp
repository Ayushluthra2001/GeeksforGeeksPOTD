//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int countZero = 0;
        int i = 0;
        int j = 0;
        while(j < arr.size()){
            if(arr[j]==0) {
                countZero++;
                
            }else{
                arr[i++]=arr[j];
                
            }
            j++;
        }
        for(int k = arr.size()-1; k>=0 && countZero>0; countZero--,k--) arr[k] = 0;
        
        return  ;
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
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
