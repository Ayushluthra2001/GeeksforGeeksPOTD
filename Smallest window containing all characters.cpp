class Solution {
public:
    string minWindow(string s, string p) {

        unordered_map<char,int> mp;

        for(char c : p)
            mp[c]++;

        int required = p.length();
        int l = 0, r = 0;

        int minLen = INT_MAX;
        int start = 0;

        while(r < s.length()) {

            if(mp[s[r]] > 0)
                required--;

            mp[s[r]]--;

            while(required == 0) {

                if(minLen > r - l + 1) {
                    minLen = r - l + 1;
                    start = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                    required++;

                l++;
            }

            r++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
