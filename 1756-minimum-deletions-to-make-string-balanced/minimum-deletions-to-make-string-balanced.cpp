class Solution {
public:
    int minimumDeletions(string s) {
        int ans = INT_MAX;
        int n = s.length();
        vector<int> leftB(n,0);
        vector<int> rightA(n,0);
         
        int countB = 0;
        //leftB pre compute 
        for (int l = 0; l<n;l++) {
            leftB[l] = countB;
            if (s[l] == 'b') {
                countB++;
            }
        }

        int countA = 0;
        //rightA precompute
        for (int r = n-1; r >= 0;r--) {
            rightA[r] = countA;
            if (s[r] == 'a') {
                countA++;
            }
        }

        for (int i = 0; i < n;i++) {
            ans = min(ans,leftB[i] + rightA[i]);
        }

        return ans;
    }
};