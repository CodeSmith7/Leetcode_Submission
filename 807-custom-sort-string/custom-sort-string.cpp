class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map <char , int > mp;
        for (char &c : s) {
            mp[c]++;
        }
        string ans = "";
        for (char &c : order) {
            while (mp[c]--) {
                ans += c;
            }
        }

        for (auto &[a,b] : mp) {
                while (b > 0) {
                    ans += a;
                    b--;
                }
            
        }

        return ans;
    }
};