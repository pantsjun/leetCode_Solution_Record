/**解题思路：使用递归，
 * 中序遍历的思路就是先遍历左子树，然后读取根节点，最后再遍历右子树
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res = {};
        if(!root){
            return res;
        }
        return helper(root, res);
    }
    vector<int>helper(TreeNode* node, vector<int> &res) {
        if (node->left)  helper(node->left, res);
        res.push_back(node->val);
        if(node->right) helper(node->right, res);
        return res;
    }
};