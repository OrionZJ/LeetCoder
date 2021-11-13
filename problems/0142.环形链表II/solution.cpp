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
        //初始化快、慢指针
        struct ListNode *fastPointer = head;
        struct ListNode *slowPointer = head;
        while (fastPointer != NULL && fastPointer != slowPointer) {
            if (fastPointer->next != NULL) {
                fastPointer = fastPointer->next->next;
                slowPointer = slowPointer->next;
            } else {
                fastPointer = fastPointer->next;
            }
        }
        if (fastPointer == NULL) return fastPointer;
        struct ListNode *temp1 = fastPointer;
        struct ListNode *temp2 = head;
        while(temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};