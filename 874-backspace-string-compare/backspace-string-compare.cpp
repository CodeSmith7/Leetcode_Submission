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
        //Aproch 1 : using substr function 
        // if (removeBackspace(s) == removeBackspace(t)) {
        //     return true;  
        // }
        // return false;

        //approach 2 : using constant space 
        int m = s.length();
        int n = t.length();

        int i = m-1;
        int j = n-1;

        int skipS = 0;
        int skipT = 0;

        //for string s
        while (i >= 0 || j >= 0) {
            
            //for string s
            while ( i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }

            //for string t
            while ( j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }

            char charS = i < 0 ? '$' : s[i];
            char chart = j < 0 ? '$' : t[j];
            i--;
            j--;

            if (charS != chart) {
                return false;
            }
            
        }
        return true;
    }
};