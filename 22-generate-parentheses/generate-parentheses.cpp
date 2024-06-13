class Solution {
public:
    vector <string> result;

    bool isValid (string s) {
        int counter = 0;
        for (char &ch : s) {
            if (ch == '(') {
                counter++;
            }
            else if (ch == ')' ) {
                counter--;
            }

            if (counter < 0) {
                return false;
            }
        }
        return counter == 0;
    }

    void solve (string& ans,int n) {
        if (ans.size() == 2*n) {
            if (isValid(ans)) {
                result.push_back(ans);
            }
            return;
        }

        //do something 
        ans.push_back('(');
        //explore
        solve (ans,n);
        //undo it 
        ans.pop_back();

        ans.push_back(')');
        solve (ans,n);
        ans.pop_back();

    
    }
    vector<string> generateParenthesis(int n){
        string ans = "";
        solve (ans,n);
        return result;
    }
};