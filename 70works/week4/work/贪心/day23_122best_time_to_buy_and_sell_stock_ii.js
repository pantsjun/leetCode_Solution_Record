/**思路:贪心
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let benifit =0;
    for(let i = 0; i < prices.length; i++) {
        let j = i-1;
        let tmp = prices[i] - prices[j];
        if(tmp> 0) {
            benifit += tmp;
        }
    }
    return benifit;
};
