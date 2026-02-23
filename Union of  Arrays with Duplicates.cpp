class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mapping;
        for(auto i : a ) mapping[i]++;
        for(auto i : b ) mapping[i]++;
        
        vector<int>result; 
        for(auto i : mapping){
            result.push_back(i.first);
        }
        
        return result;
        
    }
};
