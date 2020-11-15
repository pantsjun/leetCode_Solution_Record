/**解题思路：组合是回溯的经典题目；回溯主要是用来解决找出所有方案的。
 * 它的优化方案是剪枝，
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    //termiatior
    let res =[];
    if (n === 0 || n<k){
        return res;
    }
    const helper = (start, path) => {
        if (path.length === k) {
            
            // 如果走到分支尽头，就把完整解送入res
            // slice()是浅拷贝。返回一个新的拷贝数组;
            // 但原数组不会受到影响
            res.push(path.slice());
            return;
        }

        // 枚举
    for(let i = start; i <= n; i++) {
        path.push(i);

        // 这步相当于剪枝，下一个搜索起点为上一个搜索起点+1
        helper(i+1, path);
        path.pop();
    }
    }

    //drillDown
    helper(1, []);
    return res;
};