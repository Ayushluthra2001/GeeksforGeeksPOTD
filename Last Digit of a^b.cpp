class Solution {
  public:
    int getLastDigit(string& a, string& b) {

        if(b == "0") return 1;

        char lastDigitOfA = a[a.length()-1];

        if(lastDigitOfA=='0' || lastDigitOfA=='1' ||
           lastDigitOfA=='5' || lastDigitOfA=='6')
            return lastDigitOfA-'0';

        int mod2 = (b.back()-'0') % 2;

        int mod4;
        if(b.size() == 1)
            mod4 = (b[0]-'0') % 4;
        else {
            int lastTwo =
                (b[b.size()-2]-'0')*10 +
                (b[b.size()-1]-'0');
            mod4 = lastTwo % 4;
        }

        if(lastDigitOfA=='9'){
            return (mod2==0) ? 1 : 9;
        }

        if(lastDigitOfA=='4'){
            return (mod2==0) ? 6 : 4;
        }

        if(lastDigitOfA=='2'){
            if(mod4==0) return 6;
            else if(mod4==1) return 2;
            else if(mod4==2) return 4;
            else return 8;
        }

        if(lastDigitOfA=='3'){
            if(mod4==0) return 1;
            else if(mod4==1) return 3;
            else if(mod4==2) return 9;
            else return 7;
        }

        if(lastDigitOfA=='7'){
            if(mod4==0) return 1;
            else if(mod4==1) return 7;
            else if(mod4==2) return 9;
            else return 3;
        }

        // lastDigitOfA == '8'
        if(mod4==0) return 6;
        else if(mod4==1) return 8;
        else if(mod4==2) return 4;
        else return 2;
    }
};
