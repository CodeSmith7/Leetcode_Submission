
//Approach 1: O(n^2) approach
// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int> st;
//         string result;

//         for (char &ch : s) {
//             if (ch == '(') {
//                 st.push(result.size());
//             } else if (ch == ')') {
//                 int len = st.top();
//                 st.pop();
//                 reverse(result.begin() + len, result.end());
//             } else {
//                 result.push_back(ch);
//             }
//         }
//         return result;
//     }
// };

//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};