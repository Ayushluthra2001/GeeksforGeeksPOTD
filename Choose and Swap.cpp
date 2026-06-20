class Solution {
  public:
    string chooseSwap(string &s) {
        vector<bool> present(26, false);

        for(char ch : s) {
            present[ch - 'a'] = true;
        }

        for(int i = 0; i < s.length(); i++) {

            present[s[i] - 'a'] = false;

            for(char ch = 'a'; ch < s[i]; ch++) {

                if(present[ch - 'a']) {

                    char c1 = s[i];
                    char c2 = ch;

                    for(int j = 0; j < s.length(); j++) {
                        if(s[j] == c1)
                            s[j] = c2;
                        else if(s[j] == c2)
                            s[j] = c1;
                    }

                    return s;
                }
            }
        }

        return s;
    }
};
