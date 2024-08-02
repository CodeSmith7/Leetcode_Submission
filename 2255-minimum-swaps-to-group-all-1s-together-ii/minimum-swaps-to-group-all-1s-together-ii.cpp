//Approach 1 : using extra space O(2*n)
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> temp(2*n);

//         for (int i = 0; i < 2*n;i++) {
//             temp[i] = nums[i%n];
//         }

//         int totalOnes = accumulate (begin(nums),end(nums),0); //window size

//         cout << "Total Ones : " << totalOnes << endl;

//         //sliding window template 
//         int i = 0;
//         int j = 0;

//         int currOnes = 0;
//         int maxCount = 0;

//         while ( j < 2*n) {
//             if (temp[j] == 1) {
//                 currOnes++;
//             }
//             if (j-i+1 > totalOnes) {
//                 currOnes -= temp[i]; //shrinking the window 
//                 i++;
//             } 
//             maxCount = max(maxCount, currOnes);

//             j++;
//         }

//         int swap = totalOnes - maxCount;

//         return swap;
//     }
// };

//Approach 2 : Without using the extra soace 
 class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int totalOnes = accumulate (begin(nums),end(nums),0); //window size

        //sliding window template 
        int i = 0;
        int j = 0;

        int currOnes = 0;
        int maxCount = 0;

        while ( j < 2*n) {
            if (nums[ j% n] == 1) {
                currOnes++;
            }
            if (j-i+1 > totalOnes) {
                currOnes -= nums[i%n]; //shrinking the window 
                i++;
            } 
            maxCount = max(maxCount, currOnes);

            j++;
        }

        int swap = totalOnes - maxCount;

        return swap;
    }
};