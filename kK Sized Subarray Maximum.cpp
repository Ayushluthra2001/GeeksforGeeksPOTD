class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int i = 0 , j = 0;
        int maxi = 0;
        while(j < arr.size() && j < k){
            maxi = max(maxi , arr[j]);
            j++;
        }
        vector<int>ans;
        ans.push_back(maxi);
        
        while(j < arr.size()){
           maxi = 0;
            for(int k = i+1; k<=j; k++){
                maxi = max(maxi , arr[k]);
            }
            ans.push_back(maxi);
           j++;
            i++;
        }
        
        
        return ans;
    }
};




// 33 38 46 24 26 6 42 28
