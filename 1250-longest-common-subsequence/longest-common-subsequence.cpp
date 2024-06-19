//Approach 1: using recursuon memoization

// class Solution {
// public:
//     int t[1001][1001];
//     int LCS(string& s1, string& s2, int m, int n) {
//         if(m == 0 || n == 0)
//             return t[m][n] = 0;
        
//         if(t[m][n] != -1)
//             return t[m][n];
        
//         if(s1[m-1] == s2[n-1])
//             return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
//         return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
        
//         memset(t, -1, sizeof(t));
        
//         return LCS(text1, text2, m, n);
//     }
// };

//Approach 2: ung bottom up (tabulation)

class Solution {
public:
    
    void printLCS(string s1,string s2, vector<vector<int> > &t,int m, int n) {
        string ans = "";
        int i = m;
        int j = n;

        while ( i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--; //move diagonally 
            }
            else {
                if (t[i-1][j] > t[i][j-1]) {
                    i--;
                } else {
                    j--;
                }

            }
        }
        reverse(begin(ans),end(ans));
        cout << "LCS -> " << ans << endl;

    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int> > t(m+1,vector<int>(n+1));

        for (int row = 0; row < m+1;row++) {
            t[row][0] = 0;
        }
        for (int col = 0; col < n+1;col++) {
            t[0][col] = 0;
        }

        for (int i = 1; i < m+1;i++) {
            for (int j = 1;j < n+1;j++) {
                if (s1[i-1] == s2[j-1] ) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max (t[i-1][j], t[i][j-1]);
                }
            }
        }
        printLCS(s1,s2,t,m,n);
        return t[m][n];
    }
};
