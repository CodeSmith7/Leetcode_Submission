class Solution {
public:
    int firstUniqChar(string s) {
      
      //using map
       int n = 0;
       n = s.size();
       if (n == 0) return -1;
       unordered_map<char ,int> mp;
       for (auto x : s) {
            mp[x]++;
       }
       for (int i = 0;i <n ;i++ ) {
           char ch = s[i];
           if (mp[ch] == 1) return i;
       }
       return -1;

    }
};