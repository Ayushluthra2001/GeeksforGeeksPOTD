//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
          int totalSum = 0;
        for(auto i : arr){
            totalSum+=i;
        }
     
      
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        
        int currSum = 0;
        
        for(int i = 0; i<arr.size(); i++){
            currSum += arr[i];
            maxi = max(maxi , currSum);
            if(currSum  < 0) currSum = 0;
            
        }
        currSum = 0;
        for(int i = 0; i<arr.size();i++){
            currSum += arr[i];
            mini = min(mini, currSum);
            if(currSum > 0) currSum = 0 ;
        }
       
        
        int maxSum = totalSum - mini;
        return max(maxSum , maxi);
        
        
        
        
        
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
