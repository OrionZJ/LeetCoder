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
        while (fastPointer != NULL) {
            if (fastPointer->next != NULL) {
                fastPointer = fastPointer->next->next;    //快指针每次走两个结点
                slowPointer = slowPointer->next;    //慢指针每次走一个结点
                if (fastPointer == slowPointer) break;    // 快指针与慢指针再次相遇说明有环
            } else {
                fastPointer = NULL;    //若快指针next为NULL，说明无环，置为NULL
            }
        }
        if (fastPointer == NULL) return NULL;    //快指针为NULL说明无环
        // 由数学推导，通过以下过程可求得第一个环结点，详见md文件
        if (fastPointer == slowPointer) {       
            struct ListNode *temp1 = fastPointer;
            struct ListNode *temp2 = head;
            while(temp1 != temp2) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
        return NULL;
    }
};