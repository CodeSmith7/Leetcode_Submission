class Solution {
public:
    
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        // int l = 0, r = height.size()-1;
        // int ans = 0;
        // int maxLeft = 0, maxRight = 0;

        // while ( l < r) {
 
        //     if (height[l] < height[r]) {
        //         maxLeft  = max(maxLeft,height[l]);
        //         ans += maxLeft - height[l];
        //         l++;
        //     } else {
        //         maxRight = max(maxRight,height[r]);
        //         ans +=maxRight -  height[r];
        //         r--;  
        //     }
 
        // }

        // return ans;



        // approach 2 : first principle 

        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};