// 解题思路:
// 使用bfs的思路: 队列负责收入每层的节点，当前层的节点都执行到就pop，
// 然后再push下一层的节点
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        auto averages = vector<double>();
        auto qu = queue<TreeNode *>();
        qu.push(root);
        while (!qu.empty())
        {
            double sum = 0;
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                auto node = qu.front();
                qu.pop();
                sum += node->val;
                if (node->left != nullptr)
                {
                    qu.push(node->left);
                }
                if (node->right != nullptr)
                {
                    qu.push(node->right);
                }
            }
            averages.push_back(sum / size);
        }
        return averages;
    }
};
int main()
{

    return 0;
}