//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int,int>mapping;
        for(int i=0;i<lines.size();i++){
            int end=lines[i][1]+1;
           mapping[end]--;
           mapping[lines[i][0]]++;
            
        }
        int sum=0;
        int maxi=0;
        for(auto i : mapping){
            sum+=i.second;
            maxi=max(maxi,sum);
        }
        return maxi;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
