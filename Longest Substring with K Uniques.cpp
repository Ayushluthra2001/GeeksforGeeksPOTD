class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i = 0 , j = 0;
        int maxi = 0;
        unordered_map<char,int>mapping;
        while(j < s.length()){
            mapping[s[j]]++;
            while(mapping.size() > k){
                mapping[s[i]]--;
                if(mapping[s[i]]==0) mapping.erase(s[i]);
                i++;
            }
            
           if(mapping.size()== k) maxi = max(maxi , j - i+1);
            j++;
            
        }
// maxi = max(maxi , j-i+1);
        
        
        return maxi==0 ? -1 : maxi;
    }
};
