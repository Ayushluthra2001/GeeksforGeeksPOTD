class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int o = 0, c = 0;
        // for(int i =0; i<s.length(); i++){
        //     int opening = 0;
        //     int closing = 0;
        //     if(s[i]=='(') o++;
        //     else c++;
        //     for(int j = 0; j<i;j++){
        //         if(s[j] == '(') opening ++;
        //     }
        //     for(int j =i; j<s.length(); j++){
        //         if(s[j] == ')') closing++;
                
        //     }
        //     if(opening == closing) return i;
        // }
        vector<int>op(s.length(),0);
        vector<int>cl(s.length(),0);
        
        for(int i =0; i<s.length(); i++){
            if(s[i] == '(') o++;
            op[i] = o;
        }
        for(int j =s.length()-1; j>=0 ; j--){
            if(s[j]==')') c++;
            cl[j] = c;
        }
        for(int i =0; i<s.length(); i++){
            if(i == 0) {
    if(cl[i] == 0) return 0;
}
else {
    if(op[i-1] == cl[i]) return i;
}
        }
       return (o > c) ? 0 : s.length();
    }
};
