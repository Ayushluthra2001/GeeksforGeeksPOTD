//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<vector<int>>list1,list2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='X') {
                    list1.push_back({i,j});
                }
                if(grid[i][j]=='Y') {
                    list2.push_back({i,j});
                }
            }
        }
        int ans=INT_MAX;
        // for(int i=0;i<list1.size();i++){
        //     cout<<list1[i][0]<<" "<<list1[i][1]<<endl;
        // }
        // cout<<endl;
        //  for(int i=0;i<list2.size();i++){
        //     cout<<list2[i][0]<<" "<<list2[i][1]<<endl;
        // }
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                // cout<<list1[i][0]<<" "<<list1[i][1]<<"list2 "<<list2[j][0]<<" "<<list2[j][1]<<endl;
                // cout<<abs(list1[i][0]-list2[j][0])+abs(list1[i][0]-list2[j][1])<<endl;
                ans=min(ans,abs(list1[i][0]-list2[j][0])+abs(list1[i][1]-list2[j][1]));
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
