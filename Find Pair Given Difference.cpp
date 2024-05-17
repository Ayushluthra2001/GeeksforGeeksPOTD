//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool find(int rem , int start,int n, vector<int>&arr){
      int end=n-1;
      while(start<=end){
          int mid=start+(end-start)/2;
          if(arr[mid]==rem) return 1;
          else if(arr[mid]<rem) start=mid+1;
          else end=mid-1;
      }
      return 0;
  }
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int rem=abs(arr[i]+x);
            
            if(find(rem,i+1,n,arr)) return 1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends
