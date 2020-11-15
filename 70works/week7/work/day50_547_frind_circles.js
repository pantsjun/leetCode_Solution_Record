/**
 * @param {number[][]} M
 * @return {number}
 */
var findCircleNum = function(M) {
    if(M.length == 0) return;
    let n = M.length;
    let count =n;
    let parent = new Array(n);
    for(let i =0; i < n; i++) {
        parent[i] = i;
    }
    const onion = (p, q) => {
        let rootP = find(p);
        let rootQ = find(q);
        if (rootP === rootQ)
            return;
        parent[rootP] = rootQ;
        count--;
    }
    const find = (p) => {
        while(p !== parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    for(let i =0; i < n; i++) {
        for(let j =0; j < n; j++) {
            if(M[i][j] === 1) {
                onion(i, j);
            }
        }
    }
    return count;
};