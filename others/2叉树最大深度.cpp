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
    int getDepth(TreeNode *node){
        if(node == nullptr) return 0; //判断指针为空的判断要放在这里，否则下面会报错
        return 1+max(getDepth(node->left), getDepth(node->right));
    }
    int maxDepth(TreeNode* root) {   
        return getDepth(root);
    }

};