class Solution {
public:
    int solve(int i, int j, int k, vector<vector<vector<int>>>& dp, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int k2 = i + j - k; // derive j2 from other indices

        if (i >= n || j >= m || k >= n || k2 >= m) return INT_MIN;
        if (mat[i][j] == -1 || mat[k][k2] == -1) return INT_MIN;

        if (i == n - 1 && j == m - 1) return mat[i][j];  // reached bottom-right

        if (dp[i][j][k] != -2) return dp[i][j][k];

        int val = mat[i][j];
        if (i != k || j != k2) val += mat[k][k2];

        int a = solve(i + 1, j, k + 1, dp, mat);
        int b = solve(i, j + 1, k, dp, mat);
        int c = solve(i + 1, j, k, dp, mat);
        int d = solve(i, j + 1, k + 1, dp, mat);

        int maxi = max({a, b, c, d});
        if (maxi == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = val + maxi;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n, -2)));

        int ans = solve(0, 0, 0, dp, mat);
        return max(0, ans);
    }
};
