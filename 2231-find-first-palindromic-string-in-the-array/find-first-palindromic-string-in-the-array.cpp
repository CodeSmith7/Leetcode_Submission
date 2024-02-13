class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() -1;
        while ( l < r ) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans;
        for (auto x : words) {
            if (isPalindrome(x)) {
                ans = x;
                cout << x << endl;
                break;
            }
        }
        return ans;
    }
};