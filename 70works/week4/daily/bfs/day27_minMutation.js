var minMutation = function(start, end, bank) {
    let used = new Set(bank);
    let level = 0;
    if(!used.has(end)) return -1;
    let queue = [];
    queue.push([start, 0]);
    let gene = ['A', 'C', 'G', 'T'];
    while(queue.length > 0) {
        let [currStr, count] = queue.shift();
        if(currStr === end) return count;
        for(let i =0; i < currStr.length; i++) {
            for(let j =0; j <gene.length; j++) {
                if(currStr[i] !== gene[j]) {
                    let d = currStr.slice(0, i) + gene[j] +currStr.slice(i+1);
                    console.error(`d: ${d}`);
                    if(used.has(d)) {
                        queue.push([d, count+1]);
                        used.delete(d);
                    }
                }
            }
        }
    }
    return -1;
};
let start = "AACCGGTT";
let end = "AACCGGTA";
let bank = ["AACCGGTA"];
minMutation(start, end, bank);
// console.log(nums);
