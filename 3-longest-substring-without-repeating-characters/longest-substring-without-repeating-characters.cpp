class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = -1;
    int maxLen = 0;
    bool set[256] = {false};
    while (i < s.size()) {
        char chAquire = s[i];
        while (set[chAquire] == true) {
            j++;
            char chRelease = s[j];
            set[chRelease] = false;
        }
        //aquire 
        set[chAquire] = true;
        //update max length
        maxLen = max(maxLen , i-j);
        i++; // Increment i to avoid infinite loop
    }
    return maxLen;
}
};