class Solution {
public:
    int longestPalindrome(string s) {
        //Approach 1 : using SET
        
        // int n = s.length();
        // unordered_set<int> st;
        // int result = 0;

        // for (char &ch : s) {
        //     if (st.count(ch) ) {
        //         result += 2;
        //         st.erase(ch);
        //     } else {
        //         st.insert(ch);
        //     }
        // }
        // if (!st.empty()) {
        //     result++;
        // }
        // return result;

        //Approach 2: using unordered map 
        int n = s.size();

        unordered_map<char,int> mp;
        for (char &ch : s) {
            mp[ch]++;
        }
        bool isOddPresent= false;
        int result = 0;
        for (auto& it: mp) {
            if (it.second %2 == 0) {
               result += it.second; 
            } else {
                result += it.second -1;
                isOddPresent = true;
            }
        }
        if (isOddPresent) {
            result++;
        }
        return result;
    }
};