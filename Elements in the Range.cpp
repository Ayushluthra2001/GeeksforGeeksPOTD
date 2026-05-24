class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        unordered_map<int,int>mapping;
        for(auto i : arr) mapping[i]++;
        
        while(start<=end){
            if(mapping.find(start) == mapping.end()) return false;
            start++;
        }
        return true;
    }
};
