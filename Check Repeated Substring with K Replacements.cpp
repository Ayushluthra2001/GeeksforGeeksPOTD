class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.length(); 
        if(n%k != 0) return false;
        
        unordered_map<string,int>mapping;
        for(int i =0; i<n; i+=k){
            string temp = "";
            int l = 0;
            for(int j =i; j<s.length() && l < k ;j++){
                temp+= s[j];
                l++;
            }
            mapping[temp]++;
        }
        
        
        
        
        if(mapping.size() >=3) return false;
        
        if(mapping.size()==1) return true;
        
        if(mapping.size()==2){
            int maxi = 0;
            int mini = INT_MAX;
            for(auto i : mapping) {
                maxi = max(maxi , i.second);
                mini = min(mini , i.second);
            }    
            // cout<<maxi <<" "<<mini<<endl;
            
            if(maxi == mini && maxi ==1) return true;
            if(mini ==1) return true;
        }
        return false;
    }
};
