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
   
   void help(TreeNode* root, vector<string>& s, string ans) {
    if (root == nullptr) {
        return; // Base case: if the node is null, return without doing anything.
    }

    // If the current node is a leaf node, add the path to the result vector.
    if (root->left == nullptr && root->right == nullptr) {
        ans += to_string(root->val);
        s.push_back(ans);
        return;
    }

    // For non-leaf nodes, continue the path traversal.
    ans += to_string(root->val) + "->";

    // Recursively call the function for the left and right subtrees.
    help(root->left, s, ans);
    help(root->right, s, ans);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> s;
    string ans = "";

    // Call the helper function starting from the root.
    help(root, s, ans);
    return s;
}

};