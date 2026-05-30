class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        if(arr.size() == 1) return ;
        vector<int>ans;
        for(int i =0; i<arr.size(); i++){
            if(i==0){
                ans.push_back(arr[0] ^ arr[1]);
            }else if(i==arr.size()-1){
                ans.push_back(arr[arr.size()-1] ^ arr[arr.size()-2]);
            }else{
                ans.push_back(arr[i-1] ^ arr[i+1]);
            }
        }
        
        for(int i = 0; i<arr.size(); i++){
            arr[i] = ans[i];
        }
        
    }
};
