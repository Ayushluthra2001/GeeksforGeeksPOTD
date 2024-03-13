//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        int i=0, j=0, n = mat.size();
        vector<int> ans;
        bool right = true;
        
        while(i < n && j < n) {
            ans.push_back(mat[i][j]);
            
            if(right) {
                if(i-1 >= 0 && j+1 < n) {
                    i--; j++;
                } else {
                    right = false;
                    j+1 < n ? j++ : i++;
                }
            } else {
                if(j-1 >= 0 && i+1 < n) {
                    j--; i++;
                } else {
                    right = true;
                    i+1 < n ? i++ : j++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
