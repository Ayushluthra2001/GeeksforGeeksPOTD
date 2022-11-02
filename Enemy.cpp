//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution

{

    public:

        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)

        {

            vector<int> row(n,0),col(m,0);

            for(int i=0;i<enemy.size();i++){

                row[enemy[i][0]-1]=-1;  

                col[enemy[i][1]-1]=-1;

            }

            int area=0;

            int maxrow=0,maxcol=0;

            int rcnt=0,ccnt=0;

            for(int i=0;i<row.size();i++){

                if(row[i]!=-1){

                    rcnt++;

                    maxrow=max(maxrow,rcnt);

                }else{

                    maxrow=max(maxrow,rcnt);

                    rcnt=0;

                }

            }

            for(int i=0;i<col.size();i++){

                if(col[i]!=-1){

                    ccnt++;

                    maxcol=max(maxcol,ccnt);

                }else{

                    maxcol=max(maxcol,ccnt);

                    ccnt=0;

                }

            }return maxrow*maxcol;

        }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends
