class Solution {
public:
    int longestPalindrome(string s) {
        //Approach 1 : using SET
        
        int n = s.length();
        unordered_set<int> st;
        int result = 0;

        for (char &ch : s) {
            if (st.count(ch) ) {
                result += 2;
                st.erase(ch);
            } else {
                st.insert(ch);
            }
        }
        if (!st.empty()) {
            result++;
        }
        return result;
    }
};