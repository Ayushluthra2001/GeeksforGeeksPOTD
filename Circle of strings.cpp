//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int node, vector<int>adj[] , vector<bool>&visited){
            
            visited[node] = 1;
            
            for(int i = 0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    dfs(adj[node][i], adj,visited);
                }
            }
    }
    int isCircle(vector<string> &arr) {
            vector<int>adj[26];
            vector<int>inDegree(26,0);
            vector<int>outDegree(26,0);
            for(int i = 0;i<arr.size();i++){
                string temp = arr[i];
                adj[temp[0]-'a'].push_back(temp[temp.length()-1]-'a');
                inDegree[temp[temp.length()-1]-'a']++;
                outDegree[temp[0]-'a']++;
            }
        
            for(int i = 0;i<26;i++){
                if(inDegree[i] != outDegree[i]) return 0;       
            }
            
           vector<bool>visited(26,0);
            dfs(arr[0][0]-'a' , adj, visited);
            
            for(int i = 0; i<26;i++){
                if(inDegree[i] && !visited[i]) return 0;
            }
            return 1 ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
