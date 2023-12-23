class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double ans = 0;
        int sum = 0;
        for (int i = 0; i < k;i++) {
            sum += nums[i];
        }

        //this is the iportant step as automatic casting takes place 
        avg = sum * 1.0 /k;
        ans = avg;
        for (int i = k;i < nums.size();i++) {
            sum += nums[i] - nums[i-k];
            avg = sum * 1.0 / k;
            ans = max (avg,ans);
        }
        
        return ans;
    }
};