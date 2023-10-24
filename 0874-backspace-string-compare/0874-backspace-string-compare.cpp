class Solution {
public:
    string removeBackspace(string &a) {
        int idx = 0;
        for (int i = 0; i < a.size() ;i++ ) {
            if (a[i] != '#') {
                a[idx++] = a[i];
            }
            else if (a[i] == '#') {
                idx--;
            }
            if (idx < 0) {
                idx = 0;
            }
        }
        return a.substr(0,idx);
        
    }
    bool backspaceCompare(string s, string t) {
        if (removeBackspace(s) == removeBackspace(t)) {
            return true;  
        }
        return false;
    }
};