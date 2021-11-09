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
    ListNode* reverseList(ListNode* head) {
        struct ListNode *dummyHead = new ListNode(0,head);    //声明虚拟头结点
        if (dummyHead->next != NULL) {
            struct ListNode *fast = dummyHead->next;    //快指针指向头结点
            struct ListNode *slow = NULL;
            while (fast->next != NULL) {
                struct ListNode *temp = fast->next;    //暂存快指针的next
                fast->next = slow;    //快指针所指结点的next指向慢指针所指结点
                slow = fast;    //慢指针移向下一元素
                fast = temp;    //快指针移向暂存的下一元素
            }
            fast->next = slow;    //将尾结点的next指向前一结点
            dummyHead->next = fast;    //虚拟头结点指向尾结点（即反转链表的头结点）
        }
        return dummyHead->next;
    }
};