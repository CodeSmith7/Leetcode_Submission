class Solution {
public:
    string removeStars(string s) {
        int idx = 0;
        for (int i = 0; i < s.size();i++) {
            if (s[i] != '*') {
                s[idx++] = s[i];
            }
            else if (s[i] == '*' && idx >= 0) {
                idx -= 1;
            }
            if (idx < 0) {
                idx = 0;
            }

        }
        return s.substr(0,idx);
    }
};