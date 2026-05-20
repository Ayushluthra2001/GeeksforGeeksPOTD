class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        while(n>0){
            if(n%2==0) return false;
            n=n/2;
        }
        
        return true;
    }
};
