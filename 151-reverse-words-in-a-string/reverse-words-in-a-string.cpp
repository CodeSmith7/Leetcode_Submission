class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string ans = "";
        while (i >= 0) {
            if (s[i] == ' ') {
                i--;
            } else {
                string temp = " ";  // temp string with one space (so that after reversing we get one space between them ) 
                int j = i;
                while (j >= 0 && s[j] != ' ') {
                    temp += s[j];
                    j--;
                }
                reverse (temp.begin(),temp.end());
                ans += temp;
                i = j;  //updation in i 
            }
        }
        ans .pop_back(); // removing extra space that is appended when last time in temp string 
        return ans;
    }
};