int n = s1.size();
        if (n != s2.size()) return false;
    
        string text = s2 + s2;
        string pat = s1;
    
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    
        for (int i = 0, j = 0; i < 2 * n; ) {
            if (text[i] == pat[j]) {
                i++; j++;
                if (j == n) return true;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    
        return false;
    }
