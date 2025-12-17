class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        
        vector<vector<int>>ans;
        
        sort(arr.begin(),arr.end());
        int i = 0 , j  =0;
        
        while(i < arr.size()){
            j = i+1;
            int lower_limit = arr[i][0];
            int upper_limit = arr[i][1];
            while(j < arr.size() && arr[j][0] <= upper_limit){
                upper_limit = max(upper_limit , arr[j][1]);
                 j++;
            }
            ans.push_back({lower_limit ,upper_limit});
            i = j;
            
        }
        
        return ans;
        
    }
};
