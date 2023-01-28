map<string,bool>dp;
    bool f(string a,string b,int al,int bl){
        if(al!=bl || al<=0 )return 0;
        string t = a+"-"+b;
        if(dp.find(t) != dp.end())return dp[t];
        
        if(al==1)return a==b;
        for(int i=0;i<al && a[i]==b[i] ;++i)if(i==al-1 && a[i]==b[i])return dp[t] = 1;
        
        for(int k=0;k<al-1;k++){
            bool o1=0,o2=0;
            
            o1 =f(a.substr(0,k+1),b.substr(0,k+1),k+1,k+1) && f(a.substr(k+1),b.substr(k+1),al-k-1,bl-k-1) ;
            if(o1)return dp[t] = 1;
            o2= f(a.substr(0,k+1),b.substr(bl-k-1),k+1,k+1) && f(a.substr(k+1),b.substr(0,bl-k-1),al-k-1,al-k-1) ;
            if(o2)return dp[t] = 1;
        }
        
        return dp[t]=0;
    }
    bool isScramble(string s1, string s2){
        int l1=s1.length(),l2=s2.length();
        if(l1!=l2)return 0;
        return f(s1,s2,l1,l2) ;
    } 
