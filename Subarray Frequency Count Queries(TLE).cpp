class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        vector<int>result;
        
        // storing freq of all element at current index
        vector<unordered_map<int,int>>mapping(arr.size());
        for(int i = 0; i<arr.size(); i++){
            if(i==0){
                unordered_map<int,int>m;
                m[arr[i]]++;
                mapping[0] = m;
                
            }else{
                
            
            unordered_map<int,int>m = mapping[i-1];
            m[arr[i]]++;
            mapping[i] = m;
        }
        }
        
        // for(int i = 0; i<mapping.size(); i++){
        //     unordered_map<int,int>m = mapping[i];
        //     cout<<i<<"Current Index"<<endl;
        //     for(auto i : m) cout<<i.first<<" "<<i.second<<endl;
            
        //     cout<<endl;
        // }
        for(int i =0; i<queries.size(); i++){
            int left   = queries[i][0];
            int right  = queries[i][1];
            int target = queries[i][2];
            if( left == 0){
                unordered_map<int,int>m;
                m = mapping[right];
                
                int count = m[target];
                result.push_back(count);
            }else{
                unordered_map<int,int>n;
                n = mapping[left-1];
                
                 unordered_map<int,int>m;
                m = mapping[right];
                
                int count = m[target];
                int count2 = n[target];
                
                result.push_back(count-count2);
            }
        }
        return result;;
    }
};
