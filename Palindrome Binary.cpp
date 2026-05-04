class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        vector<int>binary;
        while(n>0){
            binary.push_back(n%2);
            n=n/2;
        }
        
        int i = 0 , j = binary.size()-1;
        while(i <= j){
            if(binary[i] != binary[j]) return false;
            i++,j--;
        }
        return true;
    }
};
