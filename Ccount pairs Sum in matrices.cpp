
class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_map<int, int> freq;
        for (const auto& row : mat2) {
            for (int b : row) {
                freq[b]++;
            }
        }

        int count = 0;
        for (const auto& row : mat1) {
            for (int a : row) {
                int b = x - a;
                if (freq.count(b)) {
                    count += freq[b]; // if b appears multiple times
                }
            }
        }

        return count;
    }
};



