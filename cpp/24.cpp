#include"comm.h"
ListNode* swapPairs(ListNode* head) {
    ListNode* cur = head;
    ListNode* after = head;
    ListNode* pre = NULL;
    ListNode* next;
    bool IsHead  = true;
    while(cur && cur->next){
        pre = cur;
        next = cur->next; 
        after = cur->next->next;
        cur->next = next->next;
        next->next = cur;
        if(pre != NULL){
            pre->next = next;
        }
        if(IsHead){
            IsHead = false;
            head = next;
        }
        cur = after;
    }
    return head;
}
ListNode* reverseList(ListNode* head){
    ListNode* cur = head;
    ListNode* pre = NULL;
    ListNode* after = head;
    while(cur){
        after = cur->next;
        cur->next = pre;
        pre = cur;
        cur = after;
    }
    return pre;
}
ListNode* reverseListCore(ListNode* head){
    if(head == NULL){
        return NULL;
    }
    ListNode* cur;
    cur->next = reverseListCore(head->next);
    return cur;
}