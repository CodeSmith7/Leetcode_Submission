class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();

        string res = string(n,'0');

        // int i = 0;

        // for (char &ch: s) {
        //     if (ch == '1') {
        //         if (res[n-1] == '1') {
        //             res [i] = '1';
        //             i++;
        //         } else {
        //             res[n-1] = '1';
        //         }
        //     }
        // }
        // return res;


        //using STL

        int count_1 = count (s.begin(),s.end(),'1');
        int j = 0;
        while (count_1 > 1) {
            res[j] = '1';
            j++;
            count_1--;
        }
        res[n-1] = '1';
        return res;
    }
};