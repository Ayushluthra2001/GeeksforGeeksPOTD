class Solution{  
private:
    long long remove(string &str , string p , int x){
        long long i = 0 , ans = 0;
        for(int j = 0; j<str.size(); j++){
            str[i++] = str[j];
            if(i >= 2 and str[i-2] == p[0] and str[i-1] == p[1]){
                i -= 2;
                ans += x;
            }
        }
        str.resize(i);
        return ans;
    }
public:
    long long solve(int X,int Y,string S){
      
      string a = "pr" , b = "rp";
      if(X < Y){
          swap(a , b);
          swap(X , Y);
      }
      return remove(S , a , X) + remove(S , b , Y);
    }
};
