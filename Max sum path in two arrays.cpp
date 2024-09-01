//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
                int i = 0;
        int j = 0;
        int total = 0;
        int sumA = 0;
        int sumB = 0;
        int n = arr1.size();
        int m = arr2.size();
        while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            total += max(sumA, sumB) + arr1[i];
            sumA = 0;
            sumB = 0;
            i++;
            j++;
        }else if (arr1[i] > arr2[j]){
            sumB += arr2[j];
            j++;
        }else{
            sumA += arr1[i];
            i++;
        }
        }
        while(i < n){
            sumA += arr1[i];
            i++;
        }
        while(j < m){
            sumB += arr2[j];
            j++;
        }
        return total + max(sumA, sumB);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
