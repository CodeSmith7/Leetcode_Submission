class Solution {
public:
    bool binarySearch (vector<int> &nums,int target) {
        int i = 0, j = nums.size()-1;

        while (i <= j) {
            int mid = (i + (j-i)/2);
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) i = mid +1;
            else j = mid -1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //Approach 1:

        // unordered_set<int> st(nums2.begin(),nums2.end());

        // for (int &num : nums1) {
        //     if (st.find(num) != st.end()) { //unorederd set take o(1) time for finding the number 
        //         return num;
        //     }
        // }

        // return -1;

        //approch 2 : using binarysearch

        for (int &num :  nums1) {
            if (binarySearch(nums2,num)) {
                return num;
            }
        }
        return -1;


    }
};