/**解题思路：
 * 使用dfs遍历，遍历一个节点就用map存储它的父节点，
 * p和q从下往上遍历，q只要访问到已被访问过的节点，那么这个节点就相当于p和q的最大公共祖先
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    let fa = [];
    let vis = [];
    const dfs = (root) => {
        if(root.left) {
            fa[root.left.val] = root;
            dfs(root.left);
        }
        if(root.right) {
            fa[root.right.val] = root;
            dfs(root.right);
        }
    }
    fa[root.val] = null;
    dfs(root);
    while(p) {
        vis[p.val] = true;
        p = fa[p.val];
    }
    while(q) {
        if(vis[q.val]) return q;
        q = fa[q.val];
    }
    return null;
};
