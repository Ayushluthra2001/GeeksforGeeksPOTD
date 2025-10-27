#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> ans;
        int n = arr1.size(), m = arr2.size();

        // Min-heap storing {sum, i, j}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        // Push the first element of each row (arr1[i] + arr2[0])
        for (int i = 0; i < min(n, k); i++)
            pq.push({arr1[i] + arr2[0], i, 0});

        while (!pq.empty() && ans.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({arr1[i], arr2[j]});
            if (j + 1 < m)
                pq.push({arr1[i] + arr2[j + 1], i, j + 1});
        }

        return ans;
    }
};
