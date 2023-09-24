//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int,int>mapping;
        unordered_map<int,int>mapping2;
        
        for(int i=0;i<n;i++){
            if(mapping.find(arr[i])!=mapping.end()) mapping2[arr[i]]++;
            mapping[arr[i]]++;
        }
        if(mapping2.size()==0) return {-1};
        vector<int>ans;
        for(auto i : mapping2){
            ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
