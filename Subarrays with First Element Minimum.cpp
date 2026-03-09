class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;
        long long count = 0;

        for(int i = 0; i < n; i++) {
            
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int idx = st.top();
                st.pop();
                count += (i - idx);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top();
            st.pop();
            count += (n - idx);
        }

        return count;
    }
};
