class Solution {
  public:
  
  int findStartPos(int start , int end , int target , vector<int>&arr){
  int pos = -1;
  
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(arr[mid] == target){
            end = mid-1;
            pos = mid;
        }else if(arr[mid]>target){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    
    return pos;
      
  }
  int findEndPos(int start, int end , int target , vector<int>&arr){
      int pos = -1;
      while(start<=end){
          int mid = start + (end - start)/2;
          if(arr[mid] == target){
              start = mid+1;
              pos = mid;
          }else if(arr[mid] > target){
              end = mid-1;
          }else{
              start = mid+1;
          }
      }
      return pos;
  }
  
  int solve(int startPoint , int endPoint , int target , vector<int>&arr){
      
      
      int startPos = findStartPos(startPoint , endPoint, target ,arr);
      int endPos = findEndPos(startPoint,endPoint,target ,arr);
      
      if(endPos == -1 && startPos == -1) return 0;
      return endPos - startPos +1;
      
      
  }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>ans;
        for(int i = 0; i<queries.size(); i++){
            int startPoint = queries[i][0];
            int target = queries[i][2];
            int endPoint = queries[i][1];
            
            
            int count = solve(startPoint , endPoint , target,arr);
            
            ans.push_back(count);
        }
        return ans;
    }
};
