/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    struct ListNode *dummyHead = new ListNode(0, head);    //设置虚拟头结点
    struct ListNode *p = dummyHead;    //结构体指针指向虚拟头结点
    while (p->next!=NULL) {
        if (p->next->val == val) {
            struct ListNode *p1 = p->next;
            p->next = p->next->next;
            delete p1;
        } else {
            p = p->next;
        }
    }
    return dummyHead->next;    //注意此处返回虚拟指针的next，即真正的头指针
    }
};