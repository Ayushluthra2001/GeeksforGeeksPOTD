//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int ans = INT_MIN;
        
        
        for(int i = 0; i<arr.size(); i++){
            int left = 0, right = 0;
            
            for(int j = i-1;j>=0; j--){
                if(arr[i] >arr[j]) {
                    left =arr[j];
                    break;
                }
            }
            for(int j =i+1;j<arr.size();j++){
                if(arr[i] >arr[j]){
                    right  =arr[j];
                    break;
                }
            }
            //cout<<left<<" "<<right<<endl;
            ans = max(ans,abs(left - right));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
