//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int>temp1(n,0);
        vector<int>temp2(n,0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    temp1[j]++;
                    temp2[i]++;
                }
            }
        }
        
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]==n-1 && temp2[i]==0) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
