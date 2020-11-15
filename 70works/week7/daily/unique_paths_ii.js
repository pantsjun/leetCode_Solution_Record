/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
//  let t1 = text1.split('');
//  let t2 = text2.split('');
    let row = text1.length;
    let col = text2.length;
    if (row === 0 || col === 0) return 0;

    //dp代表text1 前i个字符与 text2前i个字符的公共子串长度
    let dp = Array.apply(null, {length: row + 1}).map(() => Array.apply(null, {length: col +1}).map(() => 0));
    for(let i = 1; i <= row; i++) {
        for(let j = 1; j <= col; j++) {
            if (text1[i-1] === text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[row][col];
};