class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int startTime = arr[0][0];
        int endTime = arr[0][1];
        
        for(int i = 1; i<arr.size(); i++){
            if(endTime <= arr[i][0]){
                startTime = arr[i][0];
                endTime = arr[i][1];
                
            }else return false;
        }
        
        return true;
        
    }
};
