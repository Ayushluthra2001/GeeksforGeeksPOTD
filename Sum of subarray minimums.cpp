class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> s;
        vector<int> prev(n,0);
        vector<int> next(n,0);

        // Next smaller element
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            
            if(s.empty()) next[i] = n;
            else next[i] = s.top();
            
            s.push(i);
        }

        while(!s.empty()) s.pop();

        // Previous smaller element
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            
            if(s.empty()) prev[i] = -1;
            else prev[i] = s.top();
            
            s.push(i);
        }

        long long sum = 0;
        int mod = 1e9+7;

        for(int i = 0; i < n; i++){
            long long left = i - prev[i];
            long long right = next[i] - i;

            sum = (sum + (left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }
};
