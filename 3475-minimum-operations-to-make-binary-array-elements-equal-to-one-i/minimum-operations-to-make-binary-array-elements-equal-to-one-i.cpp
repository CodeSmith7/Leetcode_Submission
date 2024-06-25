class Solution {
public:
    //k == 3
    int minOperations(vector<int>& nums) {
         int n = nums.size();

        deque<int> dq;

        int flips = 0;
        int k = 3;
        vector<bool> isFlipped(n, false);
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k ){
                flipCountFromPastForCurri -= dq.front(); //[i-k] index
                dq.pop_front();                     
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                dq.push_back(1);
                flips++;
            } else {
                dq.push_back(0);
            }
        }

        return flips;
        
    }
};