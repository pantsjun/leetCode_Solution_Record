/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {

    if(obstacleGrid.length <0) return 0;
    if(obstacleGrid[0][0] === 1) return 0;
    let row = obstacleGrid.length;
    let col = obstacleGrid[0].length;
    const dp = Array.apply(null, {length: row + 1}).map(
        ()=> Array.apply(null, {length: col + 1}).map(() => 0));
    dp[1][1] = 1;

    //遍历的length得用dp的长度，而不能用obstacleGrid的长度
    for(let i = 1; i < dp.length; i++) {
        for(let j = 1; j < dp[i].length; j++) {
            if(obstacleGrid[i-1][j-1] === 1 || i === 1 && j === 1) continue;
            dp[i][j] = dp[i-1][j] + dp [i][j-1];
        }
    }
    console.error(dp[row][col]);
    return dp[row][col];
};
let obsobstacleGrid =  [[0,0,0],[0,1,0],[0,0,0]];
uniquePathsWithObstacles(obsobstacleGrid);