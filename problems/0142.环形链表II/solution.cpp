/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //初始化虚拟头结点
        struct ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        //初始化快、慢指针
        struct ListNode *fastPointer = dummyHead;
        struct ListNode *slowPointer = dummyHead;
        int fastStep = 0;
        int slowStep = 0;
        while (fastPointer != NULL && fastPointer != slowPointer) {
            if (fastPointer->next != NULL && fastPointer->next->next != NULL) {
                fastPointer = fastPointer->next->next;
                fastStep += 2;
                slowPointer = slowPointer->next;
                slowStep++;
            }
        }
    }
};