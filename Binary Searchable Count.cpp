class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        vector<int>temp = arr;
        // sort(temp.begin(),temp.end());
        // unordered_map<int,int>mapping;
        // for(int i =0; i<arr.size(); i++) mapping[arr[i]] = i;
        
        int count = 0;
        for(int target =0; target<arr.size(); target++){
            unordered_map<int,int>visited;    
            int i =0 ,j = arr.size()-1;
            while( i<=j){
             int mid = i + (j-i)/2;
             
                if(arr[mid ]== arr[target]){
                    count++;
                    break;
                }else if(arr[mid] >arr[target]){
                    if(visited.find(arr[mid])!=visited.end()) break;
                    visited[arr[mid]]++;
                    j = mid-1;
                }else{
                    if(visited.find(arr[mid])!=visited.end()) break;
                    visited[arr[mid]]++;
                    i = mid+1;
                }
            }
            
        }
        return count;
    }
};
