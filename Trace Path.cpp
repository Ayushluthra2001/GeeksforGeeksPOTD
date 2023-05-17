int isPossible(int r, int c, string s){
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='U'){
                    mp['U']++;
                    if(mp['D']!=0)
                    mp['D']--;
                }
                
                if(s[i]=='D'){
                    mp['D']++;
                    if(mp['U']!=0)
                    mp['U']--;
                }
                if(s[i]=='R'){
                    mp['R']++;
                    if(mp['L']!=0)
                    mp['L']--;
                }
                
                if(s[i]=='L'){
                    mp['L']++;
                    if(mp['R']!=0)
                    mp['R']--;
                }
            if(mp['R']>=c or mp['L']>=c)return 0;
            if(mp['U']>=r or mp['D']>=r)return 0;
        }
        
            return 1;
        
        
    }
