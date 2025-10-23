class Solution {
  public:
  
    int find(int x1, int x2, int y1 , int y2){
        return (x2-x1)*(x2-x1) + (y2-y1) *(y2-y1);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>>ans;
        unordered_map<int,vector<vector<int>>>mapping;
        priority_queue<int,vector<int>,greater<int>>pq;
        int index = 0;
        for(int i = 0; i<points.size(); i++){
            int x1 = 0;
            int x2 = points[i][0];
            int y1 = 0;
            int y2 = points[i][1];
            int result = find(x1,x2,y1,y2);
            pq.push(result);
            mapping[result].push_back(points[i]);
           
        }
        while(!pq.empty() && k>0){
            vector<vector<int>>temp = mapping[pq.top()];
            pq.pop();
            for(auto i : temp){
                ans.push_back(i);
                k--;
                if(k<=0) return ans;
            }
            
        }
        
        return ans;
    }
};
