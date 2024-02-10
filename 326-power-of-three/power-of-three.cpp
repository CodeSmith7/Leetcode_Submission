class Solution {
public:
    bool isPowerOfThree(int n) {
        unsigned int maxi = pow(3,19);
        if (n == 0) return false;
        return (maxi % n ? false: true);        
    }
};