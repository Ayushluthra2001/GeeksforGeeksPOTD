class Solution {
  public:
    int minVal(int a, int b) {
       int bitcnt=__builtin_popcount(b);
       int ans=0;
       for(int i=30;i>=0;i--){
           if(a&(1<<i)&&bitcnt>0){
               ans+=(1<<i);
               bitcnt--;
           }
       }
       if(bitcnt>0){
           for(int i=0;i<=30;i++){
               if(!(a&(1<<i))&&bitcnt>0){
                   ans+=(1<<i);
                   bitcnt--;
               }
           }
       }
       return ans;
    }
};
