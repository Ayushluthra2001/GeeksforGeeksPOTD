//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int>ans;
        int count=0;
        int startingrow=0,startingcol=0,endingrow=n-1,endingcol=m-1;
        
       
            for(int i=startingcol;i<=endingcol;i++){
                ans.push_back(matrix[startingrow][i]);
                
                
                
            }
            startingrow++;
            for(int i=startingrow;i<=endingrow;i++){
                ans.push_back(matrix[i][endingcol]);
                
            }
            if(n==1) return ans;
            endingcol--;
            for(int i=endingcol;i>=startingcol;i--){
                ans.push_back(matrix[endingrow][i]);
               
            }
            if(m==1) return ans;
            endingrow--;
            for(int i=endingrow;i>=startingrow;i--){
                ans.push_back(matrix[i][startingcol]);
               
                
            
        }
        startingcol++;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
