class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int buy = -1;
        int sell = -1;
        int maxi = 0;
        for(int i = 0; i<prices.size(); i++){
            if(buy == -1){
                buy = prices[i];
                
            }else if(buy!= -1){
                if(prices[i] > buy){
                   if(prices[i] > sell){
                       maxi = max(maxi , prices[i] - buy);
                       sell = prices[i];
                   }
                }else if(prices[i] < buy){
                    buy = prices[i];
                    sell = -1;
                }
            }
        }
        return max(maxi, sell - buy);
    }
};
