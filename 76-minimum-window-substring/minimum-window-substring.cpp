class Solution {
public:
    
    string minWindow(string s, string t) {
        // string ans = "";
        // unordered_map<char,int> mp2;
        // for (auto x : t) {
        //     mp2[x]++;
        // }
        // int mcnt = 0;
        // int desiredcnt = t.size();
        // unordered_map<char,int> mp1;
        // int i = -1;
        // int j = -1;

        // while (true) {
        //     bool f1 = false; 
        //     bool f2 = false;

        //     //acquire 
        //     while (i < s.size()-1 && mcnt < desiredcnt ) {
        //         i++;
        //         char ch = s[i];
        //         mp1[ch]++;
        //         if (mp1[ch] <=  mp2[ch] ) {
        //             mcnt++;
        //         }
        //         f1 = true; 
        //     }

        //     while( j < i && mcnt < desiredcnt) {
        //         string pans = s.substr(j+1,i+1);
        //         if (ans.size() == 0 || pans.size() < ans.size()) {
        //             ans = pans;
        //         }
        //         J++;
        //         char ch 
        //     }
        // }
        

        // return ans;
        
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        /// UPVOTE !
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};