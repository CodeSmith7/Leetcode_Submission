class Solution {
public:
    long long fact (long long a) {
        if (a == 0) return 1;
        return a * fact(a-1);
    }
    long long countSubstrings(string s, char c) {
       //Approach 1  :

        // long long count = 0;
        // long long ans = 0;

        // for (char &ch : s) {
        //     if (ch == c) {
        //         ans += 1;
        //         ans += count;
        //         count += 1;
        //     }
        // }
        // return ans;

        // Approach 2 : using maths 
        long long count = 0;

        for (char &ch : s ) {
            if (ch == c) count++;
        }

        return count *(count-1)/2 + count;



    }
};