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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int LengthA = 0;
        int LengthB = 0;
        struct ListNode *dummyHeadA = new ListNode(0);
        struct ListNode *dummyHeadB = new ListNode(0);
        dummyHeadA->next = headA;
        dummyHeadB->next = headB;
        struct ListNode *pointerA = dummyHeadA;
        struct ListNode *pointerB = dummyHeadB;
        for (struct ListNode *a = dummyHeadA; a->next != NULL; a = a->next) 
            LengthA++;
        for (struct ListNode *b = dummyHeadB; b->next != NULL; b = b->next) 
            LengthB++;
        if (LengthA > LengthB) {
            for (int i = 0; i < LengthA - LengthB; i++)
                pointerA = pointerA->next;
        } else {
            for (int i = 0; i < LengthB - LengthA; i++)
                pointerB = pointerB->next;
        }
        while (pointerA->next != pointerB->next) {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }

    }
};