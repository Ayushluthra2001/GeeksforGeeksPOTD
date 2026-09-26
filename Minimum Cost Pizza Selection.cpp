class Solution {
public:
    int area = 0;
    int small = 0, medium = 0, large = 0;
    int sc = 0, mc = 0, lc = 0;

    vector<int> dp;

    int solve(int currArea) {
        // Required area reached
        if (currArea >= area)
            return 0;

        
        if (dp[currArea] != -1)
            return dp[currArea];

        int first = sc + solve(currArea + small);
        int second = mc + solve(currArea + medium);
        int third = lc + solve(currArea + large);

        return dp[currArea] = min({first, second, third});
    }

    int minimumCost(int x, int s, int m, int l,
                    int cs, int cm, int cl) {

        area = x;
        small = s;
        medium = m;
        large = l;

        sc = cs;
        mc = cm;
        lc = cl;

        dp.assign(area, -1);

        return solve(0);
    }
};
