class Solution {
  public:
  
  bool find(int x, vector<int>&arr){
      int start = 0 , end = arr.size()-1;
      while(start <= end){
          int mid = start +(end - start)/2;
          
          if(arr[mid] == x) return true;
          else if(arr[mid] > x){
              end = mid-1;
              
          }else start = mid+1;
      }
      
      return false;
  }
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>result;
        
        // int start = find(low,arr);
        // int end = find(high,arr);
        
        // int actualDiff = end - start-1;
        // int currDiff = end - start -1;
        
        // return actualDiff - currDiff;
        for(int i = low; i <= high; i++){
            if(!find(i,arr)){
               result.push_back(i);
            }
        }
        
        return result;
        
    }
};
