/**双指针的经典应用，
 * 如果要删除倒数第n个节点，
 * 让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。
 * 删掉slow所指向的节点就可以了。
 */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *dummyHead = new ListNode(0,head);    //初始化虚拟头结点
        struct ListNode *fastPointer;
        struct ListNode *slowPointer;
        if (dummyHead->next != NULL) {
            fastPointer = dummyHead->next;    //快指针指向头结点
            slowPointer = dummyHead;    //慢指针指向虚拟头结点
            for (int i = 0; i < n-1; i++) {
                if (fastPointer->next != NULL)
                    fastPointer = fastPointer->next;    //快指针与慢指针拉开到n个间隔
            }
            while (fastPointer->next != NULL) {    //快慢指针同时移动
                fastPointer = fastPointer->next;
                slowPointer = slowPointer->next;
            }
            struct ListNode *temp = slowPointer->next;    //暂存后一结点地址
            slowPointer->next = temp->next;   //删除慢指针后一结点
            delete temp;
        }
        return dummyHead->next;
    }
};