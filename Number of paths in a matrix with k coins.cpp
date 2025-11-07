class Solution {
public:
    int solve(vector<vector<int>>& mat, int k,int i, int j, string temp, 
    unordered_map<string,int>&paths,vector<vector<vector<int>>>&dp) {
        if(i >= mat.size() || j >= mat[0].size()) return 0;
        
        temp += "(" + to_string(i) + "," + to_string(j) + "," + to_string(mat[i][j]) + ")";
        k -= mat[i][j];
        if(k<0) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(i == mat.size()-1 && j == mat[0].size()-1) {
            if(k == 0 && paths.find(temp) == paths.end()) {
                paths[temp]++;
                return 1;
            }
            return 0;
        }
        
        int choiceOne = solve(mat, k, i+1, j, temp, paths,dp);
        int choiceTwo = solve(mat, k, i, j+1, temp, paths,dp);

        return dp[i][j][k] = choiceOne + choiceTwo;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        unordered_map<string,int> paths;
       vector<vector<vector<int>>>dp(mat.size()+1, vector<vector<int>>(mat[0].size()+1,vector<int>(k+1,-1)));
        return solve(mat, k, 0, 0, "", paths,dp);
    }
};
