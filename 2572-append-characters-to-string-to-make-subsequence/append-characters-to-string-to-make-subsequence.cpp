class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;
        int ans = t.size();
        int idx = 0;
        for (int i = 0; i < s.size();i++) {
            if (s[i] == t[idx] ) {
                ans--;
                idx++;
            }
        }
        return ans;
    }
};