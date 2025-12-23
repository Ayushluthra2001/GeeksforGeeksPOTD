class Solution {
  public:
  
  int solve(int x, int y , vector<int>&arr){
      int start = 0 , end = arr.size()-1;
      int posX = -1;
      int posY = -1;
      while(start <= end){
         int mid = start + (end - start)/2;
         
         if(arr[mid] == x){
             posX = mid;
             end = mid-1;
         }else if(arr[mid] > x){
             end = mid-1;
         }else start = mid+1;
      }
      if(posX==-1 ) posX = start;
      start = 0 ,end = arr.size()-1;
      while(start<=end){
          int mid = start + (end  - start)/2;
          if(arr[mid] == y){
              posY = mid;
              start = mid+1;
          }else if(arr[mid] > y){
             end = mid-1;
          }else start = mid+1;
      }
      
      
      
      if(posY == -1) posY = start-1;
      //cout<<x<<" "<<y<<" "<<posX<<" "<<posY<<endl;
      return posY - posX + 1;
  }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i = 0; i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int get  = solve(start, end, arr);
            ans.push_back(get);
        }
        
        return ans;
        
    }
};
// start = 4 end = 4
// mid = 2  y = 6
// 1 2 4 5 8 



