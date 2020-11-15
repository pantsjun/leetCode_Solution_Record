var permute = function(nums) {
    let visited = [];
    let path = [];
    let res=[];
    if (nums.length < 0){
        return res;
    }
    //sort用法弄错，这题重点就是要先排序！！！
    nums.sort((a,b) => a - b);

    const dfs = (visited, path) => {
        if (path.length == nums.length) {
            console.error(`遍历完的路径${path}`);
            res.push(path.slice());
        }
        for(let i =0; i< nums.length; i++) {
            if (visited[i]) continue;
            if(i>0 && nums[i] === nums[i-1] && !visited[i-1]) continue;
            path.push(nums[i]);
            console.error(`开始遍历的路径${path}`);
            visited[i] = true;
            dfs(visited.slice(), path.slice());
            path.pop();
            console.error(`开始回溯的路径${path}`);
            visited[i] = false;
        }
    }
    dfs(visited, path);
    return res;
};
let nums = [3,3,0,3];
let res = permute(nums);
console.log(res);
