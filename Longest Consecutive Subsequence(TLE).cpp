//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int solve(vector<int>& arr , int currIndex, int lastIndex){
        if(currIndex >= arr.size()) return 0;
        if(lastIndex==-1){
            int pic = 1+solve(arr,currIndex+1,currIndex);
            int notPic = solve(arr,currIndex+1,-1);
            
            return max(pic , notPic);
        }else{
            
            int pic = 0,notPic =0;
            if(arr[lastIndex] < arr[currIndex] && arr[currIndex] -arr[lastIndex]==1) pic = 1 + solve(arr,currIndex+1,currIndex);
            notPic = solve(arr,currIndex+1,lastIndex);
            return  max(pic, notPic);
        }
        return -1;
    }
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        return solve(arr,0,-1);
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
