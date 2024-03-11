class Solution {
public:
    string customSortString(string order, string s) {
        //unordered_map <char , int > mp;
        int count[26] = {0};
        for (char &c : s) {
            count[c-'a']++;
        }
        string ans = "";
        for (char &c : order) {
            while (count[c-'a']--) {
                ans += c;
            }
        }

       for (char &ch : s ) {
           if (count [ch-'a'] > 0) {
               ans += ch;
           }
       }

        return ans;
    }
};