//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   

public:

    int minIteration(int N, int M, int x, int y){    

        queue<pair<int,int>>q;

        q.push({x,y});

        vector<pair<int,int>>v;

        v.push_back({-1,0});

        v.push_back({1,0});

        v.push_back({0,1});

        v.push_back({0,-1});

        vector<vector<int>>vis(N+1,vector<int>(M+1,0));

        int ans=0;

        vis[x][y]=1;

        while(q.empty()==false){

            int c=q.size();

            for(int i=0;i<c;i++){

                pair<int,int>p=q.front();

                q.pop();

               // cout<<p.first<<" "<<p.second<<"\n";

                for(pair<int,int>it:v){

                    int xc=p.first+it.first;

                    int yc=p.second+it.second;

                    if(xc>=1&&yc>=1&&xc<=N&&yc<=M&&vis[xc][yc]==0){

                        //cout<<xc<<" "<<yc<<"\n";

                        vis[xc][yc]=1;

                        q.push({xc,yc});

                    }

                }         

            }

            ans++;

        }

        ans--;

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
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
