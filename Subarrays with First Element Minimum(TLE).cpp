class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
      
          int count = 0;
        for(int i = 0; i<arr.size(); i++){
           
            int mini = arr[i];
            int currMini = 0;
            for(int j = i; j<arr.size();j++){
                currMini = arr[j];
                 if(mini > currMini) break;
                 count++;
                   
            }
        }
      
        // for(auto i : subarray){
        //     vector<int>temp = i;
        //     int mini = *min_element(temp.begin(),temp.end());
        //     if(temp[0] == mini) count++;
        // }
        
        
        return count;
    }
};
