//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        
        stack<int> st;
        st.push(asteroids[0]);
        
        for(int i=1;i<N;i++){
            
            int curr = asteroids[i];
            
            if(curr < 0){
                
                if(st.top() > 0){   //collide
                   
                    while(!st.empty() && st.top() > 0 && abs(curr) > st.top()){
                        st.pop();
                    }
                    if(st.empty()){ st.push(curr);continue;}
                    
                    if(st.top() > 0){
                         int t = st.top();
                        st.pop();
                        if(abs(curr) != t){
                            if(abs(curr) > t) st.push(curr);
                            else st.push(t);
                        }
                    }
                    else st.push(curr);
                   
                 
                }
                else                //no collision
                    st.push(curr);
            }else{
                st.push(curr);
            }
        }
       
       vector<int> answer;
       
       while(!st.empty()) {answer.push_back(st.top()); st.pop();}
       reverse(answer.begin(), answer.end());
       return answer;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
