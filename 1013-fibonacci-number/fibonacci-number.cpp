class Solution {
public:
    int solve (int n  , vector<int>& dp) {
       
        if (n <= 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = solve (n-1, dp) + solve (n-2,dp);
    }
    int fib(int n) {
       //Top down Memoization

        // if (n <= 1) {
        //     return n;
        // }
        // vector <int>  dp (n+1, -1);
        
        // solve(n,dp); 
        
        // return dp[n];

        //Bottom UP Tabulation

        // if (n <= 1) {
        //     return n;
        // }

        // vector<int> dp(n+1,-1);

        // //definiing the the sate dp[i] = i'th fibnacci number  
        // dp[0] = 0;
        // dp[1] = 1;

        // for (int i = 2; i <= n;i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        // using constant space 
        if ( n <= 1) {
            return n;
        }
        int c = 0;
        int a = 0, b = 1;

        for (int i = 2; i <= n; i++) {
            c = a+b;
            a = b;
            b = c;
        }

        return c;

    }
};