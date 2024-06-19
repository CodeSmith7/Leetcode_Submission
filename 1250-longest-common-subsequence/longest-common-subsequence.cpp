// class Solution {
// public:
//     int t[1001][1001];

//     int solve (string text1, string text2,int i ,int j) {
//         if (i >= text1.size() || j >= text2.size()) {
//             return 0;
//         }
//         if (t[i][j] != -1) {
//             return t[i][j];
//         }

//         if (text1[i] == text2[j]) {
//             return t[i][j] = 1 + solve (text1,text2,i+1,j+1);
//         } else {
//             return t[i][j] = max(solve (text1,text2,i+1,j), solve (text1,text2,i,j+1));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         memset(t,-1,sizeof(t));
//         return solve (text1,text2,0,0);
//     }
// };

class Solution {
public:
    int t[1001][1001];
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        memset(t, -1, sizeof(t));
        
        return LCS(text1, text2, m, n);
    }
};
