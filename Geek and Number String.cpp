class Solution{
public:
    int minLength(string s, int n) {
        stack<int>st;
        int arr[]={9,2,1,4,3,6,5,8,7,0};
        for(char ch: s){
            int key=ch-'0';
            if(st.empty()){
                st.push(key);
            }else{
                if(st.top()==arr[key]){
                    st.pop();
                }else{
                    st.push(key);                                                                                                        
                }
            }
            
        }
        return st.size();
    } 
};
