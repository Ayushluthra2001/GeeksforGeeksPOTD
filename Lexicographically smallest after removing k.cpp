class Solution {
public:
    string lexicographicallySmallest(string &s, int k) {

        int n = s.length();

        // Correct power of 2 check
        if ((n & (n - 1)) == 0) {
            k /= 2;
        } else {
            k *= 2;
        }

        if (k >= n) return "-1";

        stack<char> st;

        for (char ch : s) {

            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // Remove remaining characters from the end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string result;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result.empty() ? "-1" : result;
    }
};
