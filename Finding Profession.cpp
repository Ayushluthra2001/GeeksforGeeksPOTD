class Solution {
  public:
    string profession(int level, int pos) {
        // code here
           int count = 0;
           pos--;
           while(pos>0){
               if(pos%2!=0) count++;
               pos = pos/2;
           }
        if(count%2==0) return "Engineer";
        
        return "Doctor";
    }
};
