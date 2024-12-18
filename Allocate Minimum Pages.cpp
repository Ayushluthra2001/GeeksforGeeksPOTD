//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isPossible(vector<int>& arr , int k , int mid){
      int count = 1, sum = 0;
      for(int i = 0; i<arr.size(); i++){
          if(sum + arr[i] <=mid){
              sum+=arr[i];
          }else {
              
              count++;
              if(count >k || arr[i] >  mid) return false;
                sum = 0;
                sum+= arr[i];
          } 
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size() ) return -1;
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
        }
        int start = 0, end = sum;
        int ans = -1;
        while(start <= end){
            int mid = start + (end- start)/2;
            if(isPossible(arr,k,mid)){
                ans = mid;
                end = mid-1;               
            }else {
                start = mid+1;
            }
        }
       
       return ans;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
