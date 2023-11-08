//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        int start=0;
        bool flag=true;
        int i=0;
        int j=0;
        int n=matrix.size();
        vector<int>ans;
    
        while(i<n ){
            if(flag){
                int k=0;
                while(k<matrix[0].size()){
                    ans.push_back(matrix[i][k]);
                    k++;
                    
                }
            }else {
                int k=matrix[0].size()-1;
                while(k>=0){
                    ans.push_back(matrix[i][k]);
                    k--;
                }
            }
            flag=!flag;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
