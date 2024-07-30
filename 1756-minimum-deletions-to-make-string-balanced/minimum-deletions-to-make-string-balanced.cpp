//Approach 1 : using stack
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < n ;i++) {

            if (!st.empty() && s[i] =='a' && st.top() == 'b') {
                st.pop();
                ans++;
            } else {
                st.push(s[i]);
            }
        }
        
        return ans;
    }
};
//Approch 2 : 
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int ans = INT_MAX;
//         int n = s.length();
//         vector<int> leftB(n,0);
//         vector<int> rightA(n,0);
         
//         int countB = 0;
//         //leftB pre compute 
//         for (int l = 0; l<n;l++) {
//             leftB[l] = countB;
//             if (s[l] == 'b') {
//                 countB++;
//             }
//         }

//         int countA = 0;
//         //rightA precompute
//         for (int r = n-1; r >= 0;r--) {
//             rightA[r] = countA;
//             if (s[r] == 'a') {
//                 countA++;
//             }
//         }

//         for (int i = 0; i < n;i++) {
//             ans = min(ans,leftB[i] + rightA[i]);
//         }

//         return ans;
//     }
// };

//Approch 3 : using constant space 
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int ans = INT_MAX;
//         int n = s.length();
//         int countB = 0;
//         int countA = 0;

//         for (char &ch : s) {
//             if (ch == 'a') {
//                 countA++;
//             }
//         }

//         for (int i = 0; i < n;i++) {
         
//             if (s[i] == 'a') {
//                 countA--;
//             }
         
//             ans = min(ans,countA+countB);
         
//             if (s[i] == 'b') {
//                 countB++;
//             }
//         }

//         return ans;
//     }
// };