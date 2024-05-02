class Solution {
public:
    int findMaxK(vector<int>& nums) {
       
       //Approach 2: using sort and two pointer 

       sort(begin(nums),end(nums));
       int ans = -1;

       int i = 0;
       int j = nums.size()-1;

        while (i < j) {
         
            if (-nums[i] == nums[j]) {
                return nums[j];
            } 
            if (-nums[i] < nums[j]) {
                 j--;
            }
            else {
                i++;
            }
        }
        return ans;
       
       //Approach 4 : using nums[i]
        // int arr[2001] = {0};
        // int ans = -1;
        
        // int result = -1;

        // for (int i = 0;i < nums.size();i++) {
        //     int counter = -nums[i] + 1000;
        //     if (arr[counter] == 1) {
        //        result = abs(nums[i]);
        //     } else if (arr[counter] == 0) {
        //         arr[nums[i] + 1000] = 1;
        //     }
        //     ans = max(ans,result);
        // }
        // return ans;
    }
};