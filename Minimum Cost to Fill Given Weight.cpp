class Solution {
  public:

    int solve(vector<int>& cost, int w, int currIndex, bool buy) {

        if (w == 0) return 0;
        if (w < 0) return 1e9;
        if (currIndex == cost.size()) return 1e9;

        int chose1 = 1e9, chose2 = 1e9;

        int notChose = solve(cost, w, currIndex + 1, buy);

        if (buy && cost[currIndex] != -1) {

            chose1 = cost[currIndex] +
                     solve(cost, w - (currIndex + 1),
                           currIndex + 1, buy);

            chose2 = cost[currIndex] +
                     solve(cost, w - (currIndex + 1),
                           currIndex, buy);

            return min(notChose, min(chose1, chose2));
        }

        return notChose;
    }

    int minimumCost(vector<int> &cost, int w) {

        int ans = solve(cost, w, 0, true);

        return (ans >= 1e9) ? -1 : ans;
    }
};+++++++++++++++++++++++++++
