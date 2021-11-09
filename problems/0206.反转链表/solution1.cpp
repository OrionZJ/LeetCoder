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
        struct ListNode *dummyHead = new ListNode(0,head);    //设置虚拟头结点
        struct ListNode *pointer;    //声明结构体指针作为反转表指针
        if (dummyHead->next != NULL) {    
            while (dummyHead->next->next != NULL)    //虚拟头指针指向链表尾元素
                dummyHead->next = dummyHead->next->next;
            pointer = dummyHead->next;    //操作指针指向表尾结点，即反转表头结点
            while (head->next != NULL) {
                struct ListNode *temp = head;
                while (temp->next->next !=NULL)
                    temp = temp->next;     //temp指针指向原表倒数第二个表尾结点
                pointer->next = temp;    //反转表指针所指结点的next指向temp所指结点
                temp->next = NULL;
                pointer = pointer->next;    //反转表指针指向新的反转表表尾结点
            }
            if (head->next = NULL) dummyHead->next = head;
        }
    return dummyHead->next;
    }
};