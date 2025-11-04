geeksforgeeks
Search...
Courses
Tutorials
Practice
Jobs

51
A


Refresh

Time (IST)	Status	Marks	Lang	Test Cases	Code
2025-11-04 12:02:51	Correct	
4
cpp	1115 / 1115	View
2025-11-04 12:01:23	Wrong	
0
cpp	1 / 1115	View
2025-11-04 11:56:40	Time Limit Exceeded	
0
cpp	1010 / 1115	View
2025-11-04 11:54:33	Time Limit Exceeded	
0
cpp	1010 / 1115	View
2025-11-04 11:52:49	Time Limit Exceeded	
0
cpp	1010 / 1115	View
C++ (17)



        



Custom Input

class Solution {
public:
    int solve(int index, vector<int>& height, vector<int>& dp) {
        if (index == height.size() - 1) return 0;
        if (dp[index] != -1) return dp[index];

        int jumpOne = abs(height[index] - height[index + 1]) + solve(index + 1, height, dp);
        int jumpTwo = INT_MAX;
        if (index + 2 < height.size()) {
            jumpTwo = abs(height[index] - height[index + 2]) + solve(index + 2, height, dp);
        }

        return dp[index] = min(jumpOne, jumpTwo);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(0, height, dp);
    }
};
