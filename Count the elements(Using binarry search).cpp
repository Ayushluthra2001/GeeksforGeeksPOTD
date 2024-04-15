//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
     
  public:
  int solve(vector<int>&b,int el){
      int start=0,end=b.size()-1;
      while(start<=end){
          int mid=start+(end-start)/2;
          if(b[mid]>el){
              end=mid-1;
          }else{
              start=mid+1;
          }
      }
      return start;
  }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int>ans;
        sort(b.begin(),b.end());
        for(int i=0;i<query.size();i++){
            int q=query[i];
            int el=a[q];
            int count=0;
            count=solve(b,el);
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
