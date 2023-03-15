class Solution{
    //Complete the function and return minimum number of operations
    public:
    int pal_req(string& s) {
        int i = 0, j = s.size() - 1;
        int ans = 0;
        while(i<=j) {
            if(s[i]!=s[j]) {
                ++ans;
            }
            ++i; --j;
        }
        return ans;
    }
    int specialPalindrome(string s1, string s2){
        int n = s1.size(), m = s2.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            string s = s1;
            int now = 0;
            if(i+m > n) continue;
            for(int j=i; j<i+m; j++) {
                if(s[j]!=s2[j-i]) {
                    ++now;
                    s[j] = s2[j-i];
                }
                if(j>=n-1-j && s[j]!=s[n-1-j] && (i<=n-1-j && n-1-j<i+m)) {
                    now = INT_MAX;
                    break;
                }
            }
            if(now==INT_MAX) continue;
            now += pal_req(s);
            ans = min(ans, now);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
