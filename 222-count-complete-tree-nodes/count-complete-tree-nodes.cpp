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
       void solve (TreeNode* root, int &c) {
        if (root==NULL) {
            return ;
        }
        c++;
        solve (root->left,c);
        solve (root->right,c);
    }
    int countNodes(TreeNode* root) {
        // int count = 0;
        // solve (root,count);
        // return count;
        if (root == nullptr) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};