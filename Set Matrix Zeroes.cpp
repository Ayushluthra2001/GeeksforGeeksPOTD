//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        for(int i = 0;i<mat.size(); i++){
            for(int j =0; j<mat[0].size();j++){
                if(mat[i][j] == 0) mat[i][j] = -1325222;
                
            }
        }
        // cout<<endl;
        // for(int i = 0;i<mat.size(); i++){
        //     for(int j =0; j<mat[0].size();j++){
        //       cout<<mat[i][j]<<" ";
                
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        for(int i =0; i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == -1325222){
                   // cout<<"Hello"<<endl;
                    for(int k = j+1;k<mat[0].size() && mat[i][k]!=-1325222; k++){
                        mat[i][k]  = 0;
                    }
                    for(int k = i+1; k<mat.size() && mat[k][j] != -1325222; k++){
                        mat[k][j] = 0;
                    }
                    for(int k = j-1; k>=0 && mat[i][k] != -1325222; k--){
                        mat[i][k]  = 0;
                    }
                    for(int k = i-1; k>=0 && mat[k][j] != -1325222; k--){
                        mat[k][j] = 0;
                    }
                }
            }
            
            
        }
        for(int i =0; i<mat.size();i ++){
                for(int j = 0; j<mat[0].size();j++){
                    if(mat[i][j] == -1325222) mat[i][j] = 0;
                }
            }
            
            return ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
