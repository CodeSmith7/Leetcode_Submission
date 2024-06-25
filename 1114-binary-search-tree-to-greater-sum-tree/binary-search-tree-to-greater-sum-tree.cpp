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
    vector<int> ans;
    
    void solve (TreeNode* root) {
        if (root == NULL) {
            return;
        }
        solve (root -> left);
        ans.push_back(root->val);
        solve (root -> right);

    }
    void greaterSumTree (TreeNode* root,int &i) {
        if (root == NULL ) {
            return;
        }
        
        greaterSumTree (root -> left,i);
        
        root -> val = ans[i++];

        greaterSumTree (root -> right, i);

    }
    TreeNode* bstToGst(TreeNode* root) {
        
        solve(root);
        
        //making the modiy array of the sum 
        int i = ans.size() -1;
        int sum = 0;

        while (i >= 0) {
            ans[i] += sum;
            sum = ans[i];
            i--;
        }
        cout << " modified array is : ->  " << endl;
        for (int &ele : ans) {
            cout << ele << " ";
        }

        int k = 0;

        greaterSumTree(root,k
        );

        return root;
    }
};