//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int start = 1;
        int i = 0;
        int count = 0;
        while(i< arr.size()){
            if(start != arr[i]){
                count++;
                if(count==k) return start;
                start++;
            }else if(start==arr[i]){
                start++;
                i++;
            }
            //cout<<i<<" "<<count<<" "<<start<<" ";
            
            
        }
        
        if(count < k) start = start + k-count-1;
        return start;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
