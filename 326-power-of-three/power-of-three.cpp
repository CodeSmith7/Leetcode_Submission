class Solution {
public:
    bool isPowerOfThree(int n) {
        // unsigned int maxi = pow(3,19);
        // if (n == 0) return false;
        // return (maxi % n ? false: true);        
        // if (n == 1) return true;
        // if (n <= 0 || n %3 !=0) return false;
        // return isPowerOfThree(n/3);
        if (n==0) return false;
        if (n == 1 ) return true;
        if (n % 3 == 0) {
            return isPowerOfThree(n/3);
        }
        else return false;
    }
};