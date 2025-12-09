class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mapping;
        for(int i =0; i<arr.size();i++){
            if(mapping.find(arr[i])!=mapping.end() && mapping[arr[i]]==1){
                ans.push_back(arr[i]);
                
            } 
            mapping[arr[i]]++;
        }
        
        
        return ans;
        
    }
};
