int shortestPath(int Num1,int Num2)
    {   
        
        vector<int>isprime(100000 ,1);
        
        //Sieve of Eratosthenes 
        for(int i =2;i<=sqrt(9999);i++)
        {
            if(isprime[i])
            {
                for(int j =i*i;j<=9999;j+=i)
                {
                isprime[j] = 0;
                } 
            }
        }
        if(!isprime[Num1] && !isprime[Num2]){return 0;}
        
        
        unordered_set<string> st; //for unique strings
        queue<pair<string,int>> q; // string ,steps 
        
        string start  = to_string(Num1);
        string end = to_string(Num2);
        
        q.push({start ,0});
        st.insert(start);
        
        //bfs
        while(!q.empty())
        {
            auto tp = q.front();
            q.pop();
            string num = tp.first;
            int steps = tp.second;
            
            if(num == end){return steps;}
            
            // change digits
            
            for(int i = 0;i<4;i++)
            {
                char org = num[i];
                
                for(char ch ='0' ;ch<='9' ;ch++)
                {
                    if(ch =='0' && i==0){continue;}
                    
                    num[i]  =ch;
                    int val = stoi(num);
                    if(isprime[val])
                    {
                        if(st.find(num) == st.end())
                        {
                            st.insert(num);
                            q.push({num , steps+1});
                        }
                    }
                    
                }
                num[i] = org; 
            }
            
        }
        

        return -1;
        

    }
