class Solution {
public:
    bool isVowel(char c) {
       return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
    }
    
    int maxVowels(string s, int k) {
    
        int ans = 0;
        int cnt = 0;
        for ( int i = 0; i < k; i++) {
            char c = s[i];
            if (isVowel(c)) {
                cnt++;
            }
        }
        ans = cnt;
        for (int i = k; i < s.size(); i++) {
            char l = s[i];
            char f = s[i-k];
            if (isVowel(l)) {
                cnt++; 
            }
            if (isVowel(f)) {
                cnt--;
            }
            ans = max(ans,cnt);
        }    
        return  ans;
     }
};