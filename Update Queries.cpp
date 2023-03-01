//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int n,int q,vector<vector<int>> & u)

        {

            vector<vector<int>>arr(n+1, vector<int>(17, 0));

            

            for(auto it : u)

            {

                int l = it[0];

                int r = it[1];

                int x = it[2];

                

                for(int i=0; i<17; i++)

                {

                    if((x>>i) & 1)

                    {

                        arr[l-1][i]++;

                        arr[r][i]--;

                    }

                }

            }

            

            for(int i=1; i<n; i++)

            {

                for(int j=0; j<17; j++)

                {

                    arr[i][j] += arr[i-1][j];

                }

            }

            

            vector<int>ans;

            

            for(int i=0; i<n; i++)

            {

                int x = 0;

                

                for(int j=0; j<17; j++)

                {

                    if(arr[i][j]) x += pow(2, j);

                }

                

                ans.push_back(x);

            }

            

            return ans;

        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
