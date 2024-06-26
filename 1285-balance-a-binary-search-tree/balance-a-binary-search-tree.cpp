/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        inorder (root -> left,nums);

        nums.push_back(root->val);

        inorder (root -> right,nums);

    }

    TreeNode* solve (int l, int r,vector<int>& nums) {
        if (l > r) {
            return NULL;
        }
        int mid = l - (l-r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(l,mid-1,nums);
        root->right = solve(mid+1,r,nums);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector <int> nums;

        inorder(root,nums);
        int n = nums.size();

        return solve (0,n-1,nums);
    }
};