/*
 * @Author: your name
 * @Date: 2020-08-24 23:17:23
 * @LastEditTime: 2020-08-25 01:14:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \70works\day1_threeSum.js
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let res = [];
    let len = nums.length;
    nums.sort((a,b)=>a-b);

    // leetcode上不能直接return,而要具体返回一个对象才行;
    //否则会报错；输入为空,输出为undefined;
    if(len <0 || len < 3)return res;
    for(let i =0; i< len; i++) {
        let L = i+1;
        let R = len-1;
        if(nums[i]>0) break;
        if(i>0 && nums[i] == nums[i-1])continue;
        while(L < R) {
            const sum = nums[i]+nums[L]+nums[R];
            if(sum === 0) {
                res.push([nums[i],nums[L],nums[R]]);
                while(L<R && nums[L]==nums[L+1]) L++;
                while(L<R && nums[R] == nums[R+1])R--;
                L++;
                R--;

            }else if (sum<0){
                L++;
            }else if(sum>0){
                R--;
            }
        }
    }
    return res;
};
let nums = [-1, 0, 1, 2, -1, -4]
threeSum(nums);
// module.exports = threeSum;
