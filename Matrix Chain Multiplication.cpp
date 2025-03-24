//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
   vector<vector<int>>dp;
    int answer(int start,int end,vector<int> &arr){
        if(end<=start) return 0;
        if(dp[start][end]!=INT_MAX) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<end;i++)  ans=min(ans, answer(start,i,arr) + answer(i+1,end,arr) + arr[start]*arr[i+1]*arr[end+1]);
        return dp[start][end]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
       int n=arr.size();
       dp.assign(n,vector<int>(n,INT_MAX));
       return answer(0,n-2,arr);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
