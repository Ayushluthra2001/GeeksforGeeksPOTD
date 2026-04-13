class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        int  j = 0;
        string result = "";
        while(j < s.length()){
            if(s[j] != ' ') {
                result+=s[j++];
            }else j++;
        }
        return result;
    }
};
