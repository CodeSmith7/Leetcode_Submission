class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int> st;
        // unordered_map<int,int> mp;
        // for (auto x: nums1 ) {
        //     mp[x]++;
        // }
        // for (auto x : nums2) {
        //     if (mp.find(x) != mp.end()) {
        //         st.insert(x);
        //     }
        // }
        // return vector<int>(st.begin(),st.end());

        //approach 1 : 

        // unordered_set<int> st1(nums1.begin(),nums1.end());

        // unordered_set<int> st2;

        // for (int &num : nums2) {
        //     if (st1.find(num) != st1.end()) {
        //         st2.insert(num);
        //     }
        // }

        // vector <int> res(begin(st2),end(st2));
        // return res;
        

        //Approach 2 : erasing from the set 

        // unordered_set<int> st1(nums1.begin(),nums1.end());

        // vector<int> res;

        // for (int &num : nums2) {
        //     if (st1.find(num) != st1.end()) {
        //         res.push_back(num);
        //         st1.erase(num);
        //     }
        // }
        // return res;

        //approch 3: binary search
        // sort(nums1.begin(),nums1.end());

        // unordered_set<int> st;

        // for (int &num : nums2) {
        //     if (binary_search(nums1.begin(),nums1.end(),num)) {
        //         st.insert(num);
        //     }

        // }

        //return vector<int>(st.begin(),st.end());

        //Aprroach 4 : two pointer approach 

        sort (nums1.begin(),nums1.end());
        sort (nums2.begin(),nums2.end());

        int i = 0;
        int j = 0;

        vector<int> res;

        while( i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                
                while ( i < nums1.size() -1 && nums1[i] == nums1[i+1]) {
                    i++;
                }
                
                while ( j < nums2.size() -1  && nums2[j] == nums2[j+1]) {
                    j++;
                }
                
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;


        
    }
};