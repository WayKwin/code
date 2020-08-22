#include"comm.h"
// 思路头插法 parition函数,注意返回的头节点一定是头插法结束后的头节点，不是原来的头节点
// [3->2->1:3]  [1->2->3:1] 注意此时head是1 
ListNode* quickSort(ListNode* head, ListNode* tail){
    if(head == NULL){
        return NULL;
    }
    if (head == tail){
        return head;
    }

    ListNode* base = head;
    ListNode* dummpy = new ListNode(1);
    dummpy->next = head;
    ListNode* cur = head->next;
    ListNode* pre = head;
    while(cur != NULL &&cur != tail){
        if(cur->val < base->val){
            pre->next = cur->next;
            ListNode* tmp = dummpy->next;
            dummpy->next = cur;
            cur->next = tmp;
            cur = pre->next;

        }else{
            pre = cur;
            cur = cur->next;
        }
    }
    head = dummpy->next;
    quickSort(head,base);
    if(base != NULL){
        quickSort(base->next,tail);
    }
    return head;
}
int main(){
    ListNode* head = new ListNode(2);
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(3);
    head->next = l1;
    l1->next = l2;
    head = quickSort(head,NULL);
    while(head != NULL){
        cout << head->val<<endl;
        head = head->next;
    }
}