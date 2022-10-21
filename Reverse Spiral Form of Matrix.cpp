//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int>ans;
        int startingrow=0;
        int startingcol=0;
        int endingrow=R-1;
        int endingcol=C-1;
        int total=R*C;
        int counter=0;
        while(counter<total){
            for(int index=startingcol;counter<total && index<=endingcol;index++){
                ans.push_back(a[startingrow][index]);
                counter++;
            }
            startingrow++;
            for(int index=startingrow;counter<total && index<=endingrow;index++){
                ans.push_back(a[index][endingcol]);
                counter++;
            }
            endingcol--;
            for(int index=endingcol;counter<total && index>=startingcol;index--){
                ans.push_back(a[endingrow][index]);
                counter++;
            }
            endingrow--;
            
            for(int index=endingrow;counter<total && index>=startingrow;index--){
                ans.push_back(a[index][startingcol]);
                counter++;
            }
            startingcol++;
            
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
