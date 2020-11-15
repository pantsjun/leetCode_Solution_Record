var permute = function(nums) {
    let path = [];
    let res =[];
    let used = {};
    const permuteHelper = (path) => {
        if(path.length === nums.length) {
            console.error(`回溯完成的path:${path}`);
            res.push(path.slice());
        }
        // for(let i = 0; i < nums.length; i++){
        //    if(nums[start] === path[i]) continue;
        //     path.push(nums[i]);
        //     permuteHelper(i+1, path);
        // }
        //没有一次编译过的问题，变量没有加声明符号
        for(const num of nums) {
            if(used[num]) continue;
            console.error(`开始回溯的path: ${path}`);
            path.push(num);
            used[num] = true;
            permuteHelper(path);
            path.pop();
            console.error(`回溯到上一层的path: ${path}`);
            used[num] = false;
            console.error(`是否遍历过: ${used[num]}`);
        }
    }
    permuteHelper(path);
    return res;

};
let nums = [1,2,3];
permute(nums);
