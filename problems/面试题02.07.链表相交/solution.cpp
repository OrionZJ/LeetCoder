// 题目链接https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
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
        int LengthA = 0;    //初始化链表A默认长度
        int LengthB = 0;    //初始化链表B默认长度
        
        //设置虚拟头结点
        struct ListNode *dummyHeadA = new ListNode(0);
        struct ListNode *dummyHeadB = new ListNode(0);
        dummyHeadA->next = headA;
        dummyHeadB->next = headB;
        
        //设置分别指向链表A、B的结构体指针
        struct ListNode *pointerA = dummyHeadA;
        struct ListNode *pointerB = dummyHeadB;
        
        //分别通过遍历取得链表A、B的长度
        for (struct ListNode *a = dummyHeadA; a->next != NULL; a = a->next) 
            LengthA++;
        for (struct ListNode *b = dummyHeadB; b->next != NULL; b = b->next) 
            LengthB++;
        
        //根据链表长度，分别将指向链表A、B的结构体指针向后对齐
        if (LengthA > LengthB) {
            for (int i = 0; i < LengthA - LengthB; i++)
                pointerA = pointerA->next;
        } else {
            for (int i = 0; i < LengthB - LengthA; i++)
                pointerB = pointerB->next;
        }

        //当A、B指针的next相同时，链表相交
        while (pointerA->next != pointerB->next) {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }
        return pointerA->next;    //返回交汇处结点
    }
};