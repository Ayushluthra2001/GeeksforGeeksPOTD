//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
       int maxWater(vector<int> &arr){
        int totalWater=0;
        int lmax=0,rmax=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            lmax=max(lmax,arr[i]);
            rmax=max(rmax,arr[j]);
            if(arr[i]<=arr[j]){
                totalWater+=lmax-arr[i];
                i++;
            }
            else{
                totalWater+=rmax-arr[j];
                j--;
            }
        }
        return totalWater;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
