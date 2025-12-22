// User function template for C++
class Solution {
  public:
  
  int solve(vector<int>&ans){
      int pos =-1;
      int start = 0 , end = ans.size()-1;
      while(start<=end){
          int mid = start + (end - start)/2;
          
          if(ans[mid]==1){
                pos = mid;
              end = mid-1;
          }else if(ans[mid]>1){
              end = mid-1;
          }else start = mid+1;
      }
      if(pos == -1) return -1;
      return ans.size()-pos;
  }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int count = -1;
        int x = 0;
        int maxi = 0;
        
        
        for(int i = 0; i<arr.size();i++){
            if(arr[i][0] == 1) return i;
            else{
                int get = solve(arr[i]);
                if(get == -1) x++;
                if(get > maxi ){
                  //  cout<<"GET "<<i<<" " <<get<<endl;
                    maxi = get;
                    count = i;
                }
            }
        }
        
        return  x== arr.size() ? -1 : count;
        
    }
};
