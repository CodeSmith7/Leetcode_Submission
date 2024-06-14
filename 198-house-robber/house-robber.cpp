class Solution {
public:
    int t[101];
    //memoization
    int solve(vector<int>& nums, int i ) {
        if ( i >= nums.size()) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int steal = nums[i] + solve(nums,i+2);
        int skip = solve (nums,i+1);

        return t[i] = max (steal,skip);
    }

    
    int rob(vector<int>& nums) {


        //memoization
        // int ans;

        // memset(t, -1,sizeof(t));

        // ans = solve (nums,0);

        // return ans;

        //bottom UP (Tabulation)

        //state definitio 

        // int n = nums.size();

        // vector<int> t(n+1,0);

        // //state definition 
        // //t[i] -> maximum stolen money till i house 

        // //no house -> i = 0
        // t[0] = 0;
        // //one house -> i =1 
        // t[1] = nums[0];

        // for (int i = 2; i <= n;i++) {
        //     int steal = nums[i-1] + t[i-2];
        //     int skip = t[i-1];

        //     t[i] = max (steal,skip);
        // }

        // return t[n];

            

        //using consstant space 
        int n = nums.size();

        int prevPrev, prev, temp;

        //state definition 
        //t[i] -> maximum stolen money till i house 

        //no house -> i = 0
        prevPrev = 0;
        //one house -> i =1 
        prev = nums[0];

        for (int i = 2; i <= n;i++) {
            int steal = nums[i-1] + prevPrev;
            int skip = prev;

            temp = max (steal,skip);

            prevPrev = prev;
            prev = temp;
        }

        return prev;

    }
};