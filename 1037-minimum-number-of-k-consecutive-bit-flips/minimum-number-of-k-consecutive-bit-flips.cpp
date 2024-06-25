//Approach 1 : (Using auxiliary array to mark Flipped indices)
// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();

//         int flips = 0;
//         vector<bool> isFlipped(n, false);
//         int flipCountFromPastForCurri = 0;

//         for(int i = 0; i < n; i++) {
//             if(i >= k && isFlipped[i-k] == true){
//                 flipCountFromPastForCurri--;                     
//             }
            
//             if(flipCountFromPastForCurri % 2 == nums[i]) {
//                 if(i+k > n){
//                     return -1;
//                 }
//                 flipCountFromPastForCurri++;
//                 isFlipped[i] = true;
//                 flips++;
//             }
//         }

//         return flips;

//     }
// };

//Approach 2 make the change in given arrauy only 

//Approach 3 using deque

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;

        int flips = 0;
        vector<bool> isFlipped(n, false);
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k ){
                flipCountFromPastForCurri -= dq.front();
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
