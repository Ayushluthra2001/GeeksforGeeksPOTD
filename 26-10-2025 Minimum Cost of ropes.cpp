class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        int minCost = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i =0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int sum = first+second;
            minCost+=sum;
            pq.push(sum);
        }
        return minCost;
        
    }
};
