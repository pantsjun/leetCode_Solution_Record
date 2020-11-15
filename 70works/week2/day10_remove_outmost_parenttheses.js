/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    let res ='';
    let open = 0;
    for(let c of S) {
        //特别注意这个计数，当条件成立自增为1了，那么下次判断时他就自增为2了，
        //所以这也是为什么，比如‘(()’判断右括号可以用open-->1，条件也成立的原因
        if(c === '(' && open++ >0) res += c;
        if(c === ')' && open-- >1) res += c;
    }
    return res;
};
