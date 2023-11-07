//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int sum=0;
        int sum2=0;
        int sum3=0;
        int i=0,j=0;
        
        while(i<n && j<n){
            sum3+=matrix[i][j];
            i++;
            j++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j)sum+=matrix[i][j];
                else if(i<j) {
                    sum2+=matrix[i][j];
                }
            }
        }
        return {sum2+sum3 , sum+sum3};
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
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
