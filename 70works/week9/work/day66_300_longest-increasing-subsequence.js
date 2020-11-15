/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let size = nums.length;
   if (size < 2) return size;
   let dp  = new Array(size).fill(1);
   for (let i = 1; i < size; i++) {
       for (let j = 0; j < i; j++) {
           if (nums[i] > nums[j]) {
               dp[i] = Math.max(dp[i], dp[j] + 1);
           }
       }
   }
   let res = 0;
   for (let k =0; k < size; k++) {
       res = Math.max(res, dp[k]);
   }
   return res;
   };