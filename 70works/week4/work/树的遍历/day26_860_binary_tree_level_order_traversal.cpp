/**
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        vector<vector<int>>res;
        if(root == nullptr) {
             return res;
        }
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            for(int i =0; i < size; i++) {
                
            TreeNode* node = qu.front();
            qu.pop();
            tmp.push_back(node->val);
            if(node->left != nullptr) {
                qu.push(node->left);
            }
            if(node->right != nullptr) {
                qu.push(node->right);
            }
            }
            res.push_back(tmp);

        }
        return res;
    }
};