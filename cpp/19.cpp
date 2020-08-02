#incldue "comm.h"
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL){
        return NULL;
    }
    ListNode* after = head;
    ListNode* pre = head;
    while(before){
        if (n == 0){
            cout << before->val;
            after = after->next;
            before = before->next;
        }else{
            before = before->next;
            n--;
        }
    }
    // 将要删除的点不用删
    if(after->next  == NULL){
        return head;
    }
    ListNode* toBeDel = after->next;
    after->next = toBeDel->next;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

