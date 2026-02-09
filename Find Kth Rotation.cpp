class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int mini = INT_MAX;
        int index = -1;
        for(int i = 0; i<arr.size(); i++){
            if(mini > arr[i]){
                mini = arr[i];
                index = i;
            }
        }
        return index - 0;
    }
};
