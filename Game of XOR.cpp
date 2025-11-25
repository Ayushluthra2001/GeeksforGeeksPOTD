class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int xorr = 0;
        
        for(int i = 0 ;i<arr.size();i++){
            int freq = (arr.size()-i) * (i+1);
            
            if(freq%2==0) continue;
            else xorr = xorr^arr[i];
        }
        
        return xorr;   
    }
};
