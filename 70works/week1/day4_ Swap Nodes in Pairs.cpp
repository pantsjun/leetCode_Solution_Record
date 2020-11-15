#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
       if (head == nullptr || head->next == nullptr) return head;
        ListNode* next = NULL;
        // 错误原因:递归不需要什么循环，因为递归本身就是循环
        // while(head!= NULL && head->next != NULL) {
        next= head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        // }
        return next;
    }
};
int main() {
    ListNode* head = new ListNode(1);
    ListNode* head1 = new ListNode(2);
    ListNode* head2 = new ListNode(3);
    ListNode* head3 = new ListNode(4);
    head->next =head1;
    head1->next =head2;
    head2->next =head3;
    Solution s;
    s.swapPairs(head);
    return 0;
}
