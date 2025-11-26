class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int OR = 0;
        for (int x : nums) OR |= x;
        return OR * (1 << (nums.size() - 1));
    }
};
