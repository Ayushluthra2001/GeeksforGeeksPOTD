//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        long long total = 0;
        sort(arr.begin(),arr.end());
        
        vector<int>ans;
        
        int start = 0, end = arr.size()-1;
        while( start < end){
            ans.push_back(arr[end--]);
            ans.push_back(arr[start++]);
            
        }
        if(start == end)ans.push_back(arr[start]);
        for(int i = 1;i<ans.size();i++){
            total+= abs(ans[i]-ans[i-1]);
        }
        
        total+=abs(ans[ans.size()-1] - ans[0]);
        return total;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
