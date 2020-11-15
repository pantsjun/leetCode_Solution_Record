/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let hashMap = {};
    for(let i=0; i < nums.length;i++) {
        let  n = target -nums[i];
        let find = hashMap[n];
        if (find!= undefined) return hashMap[find,i];
        else hashMap[nums[i]] = i;
    }
};
let nums = [2,7,11,15];
let target = 9;
twoSum(nums, target);
