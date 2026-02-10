class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int ans = -1;
        int maxi = *max_element(arr.begin(),arr.end());
        
        
        for(int i = 1; i<=maxi; i++){
            int currTime  = 0;
            int mini = maxi;
            for(int j = 0; j<arr.size();j++){
                if(arr[j] % i==0) currTime += arr[j] / i;
                else {
                    
                    currTime+= (arr[j]/i) + 1;
                }
                
            }
            // cout<<currTime <<" "<<i<<endl;
            if(currTime <= k) return i;
        }
        
        
        
        return ans;
        
    }
};
