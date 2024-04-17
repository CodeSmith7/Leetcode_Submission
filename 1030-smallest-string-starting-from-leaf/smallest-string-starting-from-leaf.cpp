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
    string result = "";

    void solveDFS (TreeNode* root,string curr) {
        if (root == NULL) {
            return;
        }
       
        curr = char(root->val + 'a') + curr;
       
        if (!root->left && !root->right) {
            if (result == "" || result > curr) {
                result = curr;
            }
            return;
        }
       
        solveDFS(root->left,curr);
        solveDFS (root->right,curr);
    } 
    string smallestFromLeaf(TreeNode* root) {
        // Approach 1 : using dfs 

        string curr = "";
        solveDFS (root,curr);
        return result;
    }
};