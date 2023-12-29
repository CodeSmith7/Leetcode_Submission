class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n != 0) {
            int rsbm = n & -n;
            n -= rsbm;
            c++;
        }
        return c;
    }
};