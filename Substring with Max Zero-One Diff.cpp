class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int countZero = 0;
        int countOne = 0;
        int maxi = 0;
        for(int i =0; i<s.length();i++){
            if(s[i] == '0'){
                countZero++;
            }else{
                countOne++;
            }
            int currMaxi = countZero - countOne;
            if( currMaxi < 0) {
                countZero = 0;
                countOne = 0;
            }else{
                maxi = max(maxi,currMaxi);
            }
        }
        if(maxi == 0) return -1;
        
        return maxi;
    }
};
