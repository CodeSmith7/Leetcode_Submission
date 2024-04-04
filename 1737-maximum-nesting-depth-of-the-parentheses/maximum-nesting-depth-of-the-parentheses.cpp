class Solution {
public:
    int maxDepth(string s) {
        //Approach 1 -> using stack
        stack<char> st;
        int result = 0;

        for (char &ch : s) {

            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }

            result = max (result, ( int )st.size()); //returns size_t
        }
        return result;
    }
};