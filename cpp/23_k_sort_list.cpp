#include"comm.h"
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto head = ListNode(0);
    auto comp = [](ListNode* const &a, ListNode* const &b){return a->val > b->val;};
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);    
    ListNode* head = new ListNode(0);
    for( auto&c : lists){
        if(c != nullptr){
            q.push(c);
        }
    }
    auto cur = &head;
    while(!q.empty()){
        cur->next = q.top(); 
        cur = cur ->next;
        q.pop();
        if(cur->next != nullptr){
            q.push(cur->next);
        }
    }
    return head.next;
}