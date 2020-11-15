// 解题思路：自顶向下层次遍历后(bfs)再用stl的reverse函数对结果函数进行翻转
//  就能得到自底向上的层次遍历
#include<iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    auto qu=queue<TreeNode*>();
        auto res = vector<vector<int>>();
        if(!root) return res;
        qu.push(root);
        while(!qu.empty()) {
            auto size = qu.size();
            auto tmp = vector<int>();
            for(int i =0; i < size; i++){
                 auto ans = qu.front();
                 qu.pop();
                 tmp.push_back(ans->val);
                if(ans->left) {
                qu.push(ans->left);
                }
                if(ans->right) {
                qu.push(ans->right);
                }
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};