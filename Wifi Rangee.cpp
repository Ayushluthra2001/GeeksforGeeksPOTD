class Solution {
public:
    bool wifiRange(string &s, int x) {

        int n = s.length();

        // left to right
        int maxi = -1;

        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                maxi = max(maxi, i + x);
            }

            if (maxi >= i && s[i] == '0') {
                s[i] = 'S';
            }
        }

        // right to left
        int mini = n;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '1') {
                mini = min(mini, i - x);
            }

            if (mini <= i && s[i] == '0') {
                s[i] = 'S';
            }
        }

        // final check
        for (char c : s) {
            if (c == '0') return false;
        }

        return true;
    }
};
