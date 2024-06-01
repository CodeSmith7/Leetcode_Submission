class Solution {
public:
    int scoreOfString(string s) {
        //Approach 1 : using STL
        // return inner_product(s.begin(), s.end() - 1, s.begin() + 1, 0, plus<>(), [](char a, char b) {
        // return abs(a - b);
        //});


        //Approach 2 : using simple for loop 

        int score = 0;

        for(int i = 0; i < s.length()-1; i++) {
            score += abs(s[i] - s[i+1]);
        }

        return score;
    }
};