
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

/*
* 解法一：迭代法
* */
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
var mergeTwoLists = function(l1, l2) {
    let newList = new ListNode(-1);
    let ptr = newList;
    while(l1 !== null && l2 !== null){
        if(l1.val <= l2.val) {
            ptr.next = l1;
            l1 = l1.next;
        } else {
            ptr.next = l2;
            l2 = l2.next;
        }
        ptr = ptr.next;
    }
    ptr.next = l1 === null? l2:l1;
    return newList.next;
};
