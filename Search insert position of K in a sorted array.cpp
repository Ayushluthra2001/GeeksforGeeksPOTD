class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
       
       int start = 0 , end = arr.size()-1;
       
       while(start<=end){
           int mid = start+(end-start)/2;
           
           
           if(arr[mid] == k) return mid;
           else if(arr[mid] > k) {
               end = mid-1;
           }else{
               start = mid+1;
           }
       }
        
        
        return start;
    }
};
