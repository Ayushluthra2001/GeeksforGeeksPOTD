class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       
        int missing = -1;
        
        unordered_map<int,int>mapping;
        for(int i =0; i<arr.size();i++){
            mapping[arr[i]]++;
        }
        for(int i =1;i<=arr.size();i++){
            if(mapping.find(i)== mapping.end()){
                missing = i;
                break;
            }
        }
        int repeated = -1;
        for(auto i : mapping){
            if(i.second ==2) {
                repeated = i.first;
                break;
            }
        }
        
        
        return {repeated , missing};
        
    }
};
