class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (string &s : details) {
            int one = s[12] - '0';
            int two = s[11] - '0';

            int age = two*10 + one;

            if (age > 60) {
                count++;
            } 

        }
        return count;
    }
};