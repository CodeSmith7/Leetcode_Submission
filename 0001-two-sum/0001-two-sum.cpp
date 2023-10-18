class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     // BRUTE FORCE APPROACH
     vector<int> temp = nums;
     vector<int> ans;

    // for( int i =0; i< nums.size();i++){
    //     for (int j = i+1;j < nums.size();j++){
    //         if (nums[i] + nums[j] == target ){
    //            ans.push_back(i);
    //            ans.push_back(j);
    //         }  
    //     }
    // }
    // return ans ;                              // Tc -> O(n^2)


    // Better approach (using hashing )     
   
     unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {          // TC -> O(n)   worst case -> O(n^2)  time = 5ms
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
 
          return {mpp[moreNeeded],i};

        }
        mpp[num] = i;
    }


    


   
    // optimal approach using two pointer 

    // sort(temp.begin(),temp.end());
    // int l =0;
    // int h = temp.size() -1 ;
    // while (l<h){
    //     int sum  = temp[l] + temp[h];
    //     if (sum  == target ) {
    //         int index1 = find(nums.begin(),nums.end(),temp[l]) - nums.begin();
    //         nums[index1] = INT_MIN;
    //         int index2 = find(nums.begin(),nums.end(),temp[h]) - nums.begin();
    //         ans.push_back(index1);
    //         ans.push_back(index2);
    //         return ans;
    //     }

    //     else if (sum < target ) l++;
    //     else h--;

    // }
     return {-1, -1 };
                                   // TC-> O(n)  + O(nlogn)
   }
};