class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        
        if(target == 0){
            for(int i =0; i<arr.size();i++){
                if(arr[i] == target ) return true;
            }
            return false;
        }
        unordered_map<int,int>mapping;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 0) continue;
            int curr = target / arr[i];
            //cout<<i<< " " <<curr<<endl;
            if(target % arr[i] == 0 && mapping.find(curr) != mapping.end()) return true;
            else {
                mapping[arr[i]]++;
            }
        }
     
        return false;
    }
};
