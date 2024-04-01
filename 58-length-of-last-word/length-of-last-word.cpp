class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int c = 0;
        
        // Remove trailing spaces
        while ( n >= 0 && s[n] == ' ') {
            n--;
        }
    
        // Count the length of the last word
        while (  n >= 0 && s[n] != ' ') {
            c++;
            n--;
        }
        cout << c << endl;
        return c;
    }
};