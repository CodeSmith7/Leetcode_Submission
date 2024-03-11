class Solution {
public:
    string customSortString(string order, string s) {
    //     Approach 1:
    //     //unordered_map <char , int > mp;
    //     int count[26] = {0};
    //     for (char &c : s) {
    //         count[c-'a']++;
    //     }
    //     string ans = "";
    //     for (char &c : order) {
    //         while (count[c-'a']--) {
    //             ans += c;
    //         }
    //     }

    //    for (char &ch : s ) {
    //        if (count [ch-'a'] > 0) {
    //            ans += ch;
    //        }
    //    }

    //     return ans;

        
        //Approach 2: 

        vector <int> index(26,-1);
        int i = 0;

        for (char &ch : order) {
            index[ch-'a'] = i;
            i++;
        }

        //lambda Expression
        auto myComprator = [&index] (char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };

        sort (begin(s),end(s),myComprator); 
        return s;
    }
};