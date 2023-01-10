//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        long long int ans=0;
        sort(arr.begin(),arr.end());
        
       
        for(int i=1;i<N;i++){
           
           
            if(arr[i-1]>=arr[i]) {
                int diff=arr[i-1]-arr[i];
                ans+=diff+1;
                arr[i]=arr[i]+diff+1;
            }
            
        }
       return ans;
    }
};
// 1 3 4 4 4 4 5 6 7
// 3



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends
