//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int a[],int N){
        if(N==0) return 0;
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1;i<N;i++){
            if(a[i]>ans.back()) ans.push_back(a[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    int removeStudents(int H[], int N) {
        // code here
        int maxi=0;
        int prev=-1;
        maxi=solve(H,N);
        
        return N-maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
