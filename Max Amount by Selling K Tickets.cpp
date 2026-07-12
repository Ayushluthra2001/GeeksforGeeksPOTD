class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int mod = 1e9+7;
        priority_queue<int>pq;
        int sum = 0;
        for(auto i : arr) pq.push(i);
        
        while(!pq.empty() && k>0){
            k--;
            int t = pq.top();
            sum = (sum + t) % mod ;
            pq.pop();
            if (t > 0)
    pq.push(t - 1);
           
        }
        return sum;
        
    }
};
