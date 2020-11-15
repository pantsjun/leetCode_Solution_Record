/**解题思路：使用队列先进先出的思想
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    let res= [];
    let queue =[];
    if(!root) return res;
    queue.push(root);
    while(queue.length > 0) {
        let len = queue.length;
        let tmp = [];
        for(let i = 0; i < len; i++) {
            let node = queue.shift();
            tmp.push(node.val);
            queue.push(...node.children);
        }
        res.push(tmp);
    }
    return res;
};
