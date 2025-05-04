//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        // unordered_map<int,int>mapping;
        for(int i = 0; i<arr.size();i++) if(arr[i] == target) return i ;
        // for(int  i = 0; i<arr.size(); i++){
        //     mapping[arr[i]] = i;
        // }
        
        // for(int i = 1; i<arr.size();i++){
        //     if(arr[i] < arr[i-1]){
        //         swap(arr[i],arr[i-1]);
        //     }
        // }
        // int start = 0, end = arr.size();
        // while( start <= end){
        //     int mid = start + (end-start)/2;
        //     if(arr[mid] == target) return mid;
        //     else if(arr[mid] > target) end = mid-1;
        //     else start = mid+1;
        // }
        
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
