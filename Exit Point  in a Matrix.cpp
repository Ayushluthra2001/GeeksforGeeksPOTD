class Solution {
public:

    pair<int,int> solve(vector<vector<int>>& mat,
                       
                        int i, int j, int n, int m, char ch) {

        

      

        if (mat[i][j] == 1) {

            mat[i][j] = 0; // important

            if (ch == 'r') {
                if (i + 1 >= n) return {i, j};
                return solve(mat, i + 1, j, n, m, 'd');
            }

            if (ch == 'd') {
                if (j - 1 < 0) return {i, j};
                return solve(mat, i, j - 1, n, m, 'l');
            }

            if (ch == 'l') {
                if (i - 1 < 0) return {i, j};
                return solve(mat, i - 1, j, n, m, 'u');
            }

            if (ch == 'u') {
                if (j + 1 >= m) return {i, j};
                return solve(mat, i, j + 1, n, m, 'r');
            }

        } else {

            if (ch == 'r') {
                if (j + 1 >= m) return {i, j};
                return solve(mat, i, j + 1, n, m, 'r');
            }

            if (ch == 'd') {
                if (i + 1 >= n) return {i, j};
                return solve(mat, i + 1, j, n, m, 'd');
            }

            if (ch == 'l') {
                if (j - 1 < 0) return {i, j};
                return solve(mat, i, j - 1, n, m, 'l');
            }

            if (ch == 'u') {
                if (i - 1 < 0) return {i, j};
                return solve(mat, i - 1, j, n, m, 'u');
            }
        }

        return {i, j};
    }

    vector<int> exitPoint(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

      

        auto p = solve(mat, 0, 0, n, m, 'r');

        return {p.first, p.second};
    }
};
