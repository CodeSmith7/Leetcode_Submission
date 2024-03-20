class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        long long ans = 0;

        for (char &ch : s) {
            if (ch == c) {
                ans += 1;
                ans += count;
                count += 1;
            }
        }
        return ans;
    }
};