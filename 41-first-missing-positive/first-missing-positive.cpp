class Solution {
public:
    // int firstMissingPositive(vector<int>& nums) {
    //     //STEP 1 : mark element which are out of range mark it as 1
    //       bool one = false ;
    //       int n = nums.size();
    //       for(int i  = 0;i<n;i++){
    //           if (nums[i] == 1)
    //             one = true;
            
    //           if(nums[i] < 1  || nums[i] > n)
    //             nums[i] =1;
    //       }

    //      if (one == false) return 1;

    //     //STEP 2 : MAP element with index 
    //      for(int i  = 0;i<n;i++){
    //          int idx = abs(nums[i]);
    //          nums[idx-1] = -abs(nums[idx-1]);
    //      }
    //     //STEP 3: find out missing index 
    //    for(int i =0 ;i< n;i++){
    //        if (nums[i] > 0) return i+1;
    //    }

    //    return n+1;
    // }

     int firstMissingPositive(vector<int>& nums) 
    {
        //Using pointers
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int k=1;
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]<=0)
                i++;
            else
            {
                if(nums[i]!=k)
                    return k;
                else
                {
                    i++;
                    k++;
                }
            }
        }
        return k;

    }
};