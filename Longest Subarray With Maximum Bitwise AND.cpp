class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int>mapping;
        int i = 0;
        int curr = 0;
        int maxi = 0;
        int ans = 0;
        while(i < nums.size()){

            int j = i+1;
            int length = 1;
            while(j < nums.size() && nums[i] == nums[j]){
                length++;
                j++;
            }
            mapping[nums[i]] = max(mapping[nums[i]] , length);
            i = j;
        }

        for(auto i : mapping) {
            if(i.first > maxi){
                maxi = i.first;
                ans = i.second;
            }
        }
         
        return ans;
    }
};
