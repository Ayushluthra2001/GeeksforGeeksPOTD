//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
        int median(vector<vector<int>> &matrix, int R, int C){
       int lo = 1, hi = 2001;
       while(lo <= hi) {
           int mid = (lo+hi)>>1;
           int cnt = 0;
           
           for(int i = 0; i < R; i++) {
               cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
           }
           
           if(cnt <= (R*C-1) / 2) lo = mid + 1;
           else hi = mid - 1;
       }
       
       return lo;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
