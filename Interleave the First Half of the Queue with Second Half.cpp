class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        vector<int>all;
        while(!q.empty()){
            
            all.push_back(q.front());
            q.pop();
        }
        vector<int>first;
        vector<int>second;
        for(int i =0; i<all.size()/2; i++){
            first.push_back(all[i]);
        }
        
        for(int j =all.size()/2 ; j<all.size();j++){
            second.push_back(all[j]);
            
        }
        // for(auto i : first) cout<<i<<" ";
        // cout<<endl;
        // for(auto j : second) cout<<j<<" ";
        
        // cout<<endl;
        int k = 0;
        int i = 0 , j = 0;
        while(k<all.size()){
            
            q.push(first[i++]);
            q.push(second[j++]);
            k+=2;
        }
       
        

        
    }
};
