//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    vector<vector<int>>result = matrix;
    int l = 0;
    for(int i = 0; i< matrix.size();i++){
        int k =matrix.size()-1;
        for(int j = 0;j<matrix[i].size();j++){
            
                result[i][j] = matrix[k][l]; 
                k--;
            
            
            
        }
        l++;
    }
    // for(auto i : result){
    //     for(auto j : i) cout<<j<<" ";
    //     cout<<endl;
    // }
    
    matrix = result;
    return;
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
