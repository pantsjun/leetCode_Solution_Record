#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
struct ListNode {
int val;
ListNode* next;
ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*>res;
        //  先存到一个vetor里
        ListNode*ptr = head;
        while(ptr != nullptr) {
            // 反向存储链表的元素
            cout<<"ptr.val"<<ptr->val<<endl;
            res.emplace_back(ptr);
            ptr = ptr->next;
        } 
        int size = res.size()-1;
        print(res);
        // 从两边比较
        for(int i =0, j = size; i < j ; i ++, j--) {
            if (res[i]->val != res[j]->val){
                return false;
            }
        }
        return true;
    }
    void print (vector<ListNode*> & res) {
        for(int i =0; i< res.size(); i++) {
            cout<<res[i]->val<<",";
        }
    }
};

int main() {

    Solution s;
    auto t1 = new ListNode(1);
    auto t2 = new ListNode(2);
    auto t3 = new ListNode(2);
    auto t4 = new ListNode(1);
    t1->next= t2;
    // t2->next = t3;
    // t3->next= t4;
    ListNode* head = t1;
    s.isPalindrome(head);
    return 0;
}