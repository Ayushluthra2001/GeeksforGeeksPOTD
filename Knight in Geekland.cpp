//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int n,m;

bool isVaild(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){return false;}
    return true;
}

vector<pair<int,int>> moves = {{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};
vector<int> ans;

void bfs(int i, int j, vector<vector<int>> &arr){
    vector<vector<int>> vis(n, vector<int>(m,0));

    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    ans.push_back(arr[i][j]);

    while(!q.empty()){
        int k = q.size();
        int sum = 0;
        for(int x=1; x<=k; x++){
            pair<int,int> node = q.front();
            q.pop();
            int ii = node.first, jj = node.second;
            // cout<<ii<<" "<<jj<<"\n";
            for(auto mov : moves){
                int a = ii+mov.first, b = jj+mov.second;
                // cout<<a<<" "<<b<<"\n";
                if(isVaild(a,b)){
                    if(vis[a][b]==0){
                        q.push({a,b});
                        vis[a][b] = 1;
                        sum += arr[a][b];
                    }
                }
            }
        }
        ans.push_back(sum);
    }
    ans.pop_back();
}



int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
    n = arr.size();
    m = arr[0].size();

    bfs(start_x, start_y, arr);

    int sz = ans.size();
    int mx = ans[0];
    int ind = 0;

    for(int i=0; i<sz; i++){
        if(ans[i]==0){continue;}

        int temp_ans = ans[i];
        int dist = ans[i]+i;
        while(dist<sz){
            temp_ans += ans[dist];
            if(ans[dist]==0){break;}
            dist += ans[dist];
        }
        if(temp_ans>mx){
            mx = temp_ans;
            ind = i;
        }
    }
    return ind;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
