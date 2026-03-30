class Solution {
  public:
  
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size();
        
        vector<vector<pair<int, int>>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=houses[i][0];
                int y1=houses[i][1];
                int x2=houses[j][0];
                int y2=houses[j][1];
                int d=abs(x2-x1)+abs(y2-y1);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        vector<bool>inMST(n, 0);

        pq.push({0, 0});

        int ans=0;

        while(!pq.empty()){
            auto [wt, node]=pq.top();
            pq.pop();

            if(inMST[node]) continue;

            inMST[node]=true;
            ans+=wt;

            for(auto &it:adj[node]){
                if(!inMST[it.first]){
                    pq.push({it.second, it.first});
                }               
            }
        }

        return ans;        
    }
};
