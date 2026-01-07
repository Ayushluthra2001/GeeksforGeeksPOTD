class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int count = 0;
        vector<int>ans;
        unordered_map<int,int>mapping;
        int i = 0 , j = 0;
        while(j < arr.size() && j < k){
            mapping[arr[j++]]++;
            
        }
        ans.push_back(mapping.size());
        while(j < arr.size()){
            mapping[arr[i]]--;
            mapping[arr[j]]++;
            if(mapping[arr[i]]==0) mapping.erase(arr[i]);
            ans.push_back(mapping.size());
            // cout<<endl;
            i++,j++;
            
            
        }
        
        return ans;
    }
};
