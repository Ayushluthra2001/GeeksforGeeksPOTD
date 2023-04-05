//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        
        for(int i = 0; i < N; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }
            else{
                for(int j = 0; j < i; j++){
                    if(arr[i] % arr[j] == 0){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};


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

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
