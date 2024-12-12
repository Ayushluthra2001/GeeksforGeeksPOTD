//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  int findFirstOcc(vector<int>& arr, int target){
      int start = 0 , end = arr.size()-1;
      int occ = -1;
      while( start <= end){
          int mid = start+ (end- start)/2;
          if(arr[mid]== target){
              occ = mid;
              end = mid-1;
          }else if(arr[mid] > target) {
              end = mid-1;
          }else {
              start = mid+1;
          }
      }
      
      return occ;
  }
  int findLastOcc(vector<int>& arr , int target){
    
      int occ = -1;
      int start = 0 , end = arr.size()-1;
      
      while(start <= end){
          int mid = start+ (end - start) / 2;
          
          if(arr[mid] == target) {
              occ = mid;
              start = mid+1;
              
              
          }else if(arr[mid] > target){
              end = mid-1;
          }else{
              start = mid+1;
          }
      }
      return occ;
  }
  public:
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int firstOcc = findFirstOcc(arr,target);
        int lastOcc = findLastOcc(arr,target);
        if( firstOcc == -1 && lastOcc==-1) return 0;
        return lastOcc-firstOcc+1;
        
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
