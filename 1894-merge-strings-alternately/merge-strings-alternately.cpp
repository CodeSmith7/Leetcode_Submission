class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i  = 0;
        int j = 0;

        string ans;
        int f = -1;
        while (i < word1.size()  && j < word2.size()) {
            if (f == -1) {
                ans += word1[i++];
                f *= -1 ;
            } else {
                ans += word2[j++];
                f *= -1;
            }
        } 
        while (i < word1.size()) {
            ans += word1[i++]; 
        }
        while (j < word2.size()) {
            ans += word2[j++];
        }

        return ans;
    }
};