class Solution {
public:
    // int minIncrementForUnique(vector<int>& nums) {
    //     sort(begin(nums), end(nums));

    //     int moves = 0;

    //     for(int i = 1; i < nums.size(); i++) {
    //         if(nums[i] <= nums[i-1]) {
    //             moves += (nums[i-1] - nums[i] + 1);
    //             nums[i] = nums[i-1]+1;
    //         }
    //     }

    //     return moves;
    // }

    //Approch 2 
     int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(begin(nums),end(nums));

        vector<int> count(maxElement + n,0);

        for (int &num : nums) {
            count[num]++;
        }

        int moves = 0;

        for (int i = 0;i < maxElement + n;i++) {
            if (count[i] <= 1) {
                continue;
            }

            int extra = count[i] -1;
            count[i+1] += extra;
            count[i] = 1;
            moves += extra;
        }

        return moves;
    }
};

