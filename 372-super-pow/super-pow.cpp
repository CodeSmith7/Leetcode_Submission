class Solution {
public:
    int MOD = 1337;
    long long power(int a, int exp) {
        int res = 1;
        while (exp) {
            if (exp & 1) {
                res = (res*1LL*a) % MOD;
            }
            a = (a*1LL*a) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int etf = 6 * 190;

        int n = b.size(), number = 0;
        for (int i = 0 ; i< n; i++) {
            number = number * 10 + b[i];
            if (number >= etf ) {
                number  %= etf;
            }
        }
        if (number == 0) {
            number = etf;
        }
        int ans = power(a, number);
        return ans; 
    }
};