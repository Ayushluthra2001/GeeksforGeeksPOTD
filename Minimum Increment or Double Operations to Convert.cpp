class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int decrementCount = 0;
        int maxDivideCount = 0;
        for(int i =0; i<arr.size(); i++){
            int divideCount =0 ;
            int x = arr[i];
            
            while(x > 0){
                if(x%2==0) {
                    divideCount+=1;
                    x=x/2;
                }else {
                    x--;
                    decrementCount++;
                }
            }
            maxDivideCount = max(maxDivideCount,divideCount);
        }
        
        return decrementCount + maxDivideCount;
    }
};
