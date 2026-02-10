class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int ans = -1;
        int maxi = *max_element(arr.begin(),arr.end());
        
        int start = 1;
        int end = maxi;
         int mini = maxi;
        while(start <= end){
            int mid = start + (end - start)/2;
            int currTime  = 0;
           
            for(int j = 0; j<arr.size();j++){
                if(arr[j] % mid==0) currTime += arr[j] / mid;
                else {
                    
                    currTime+= (arr[j]/mid) + 1;
                }
                
            }
            if(currTime <= k){
                mini = min ( mini , mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
            // cout<<currTime <<" "<<i<<endl;
            
            
           
        }
        
        
        
        return mini;
        
    }
};
