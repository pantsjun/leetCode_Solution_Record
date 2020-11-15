/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 * 解题思路:使用反转数组实现
 */
var rotate = function(nums, k) {
    let n = k % nums.length;
    reverse(nums,0, nums.length-1);
    reverse(nums,0, n-1);
    reverse(nums, n, nums.length-1);
    return nums;
};
var reverse = function (nums,start, end) {
    while(start　< end){
        let tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start ++;
        end--;
    }
}
