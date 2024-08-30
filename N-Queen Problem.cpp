//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int r , int c , vector<vector<int>>&board){
        
        
        for(int i = r-1; i>=0; i--){
            if(board[i][c] == 1) return false;
        }
        for(int i = c-1;i>=0;i--){
            if(board[r][i] == 1) return false;
            
        }
        for(int i = r-1 , j = c-1 ; i>=0 && j>=0 ; i--, j-- ){
            if(board[i][j] == 1) return false;
        }
        
        for(int i = r-1 , j = c+1 ; i>=0 && j<board.size() ; i-- ,j++){
            if(board[i][j] == 1) return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& board , int currRow , vector<int>& temp, vector<vector<int>>&ans, int n){
        
        if(currRow >=n){
            ans.push_back(temp);
            return ;
        }
        
        for(int i = 0; i<n; i++){
            if(isValid(currRow , i, board)){
                temp.push_back(i+1);
                board[currRow][i] = 1;
                solve(board,currRow+1, temp,ans , n);
                board[currRow][i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>temp;
        solve(board,0  , temp , ans , n);
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
