//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        
        vector<pair<int,int>>x,y;
        int ans=1e9;
        
        //traverse the grid
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                
                //saving indeces of occourance of X
                if(grid[p][q]=='X'){
                    x.push_back({p,q});
                }
                //saving indeces of occourance of Y
                else if(grid[p][q]=='Y'){
                    y.push_back({p,q});
                }
            }
        }
        
        
        //ans calculation
        for(int p=0;p<x.size();p++){
            for(int q=0;q<y.size();q++){
                ans=min(ans,abs(x[p].first-y[q].first)+abs(x[p].second-y[q].second));
            }
            if(ans==1){
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
