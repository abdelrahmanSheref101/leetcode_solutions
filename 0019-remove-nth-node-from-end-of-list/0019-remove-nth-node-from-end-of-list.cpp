class Solution {
ListNode *revers_list(ListNode* head){
    if(!head||!head->next)
        return head;
    
    ListNode* cur=head;
    ListNode* prev=nullptr;
    while(cur){
        ListNode * tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    return prev;
}
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * newHead=revers_list(head);
        ListNode * cur=newHead,* prev=nullptr;
        for (int i = 0; i < n-1 && cur; i++,prev=cur,cur=cur->next)
        {
        }
        if(prev)
            prev->next=cur->next;
        if(newHead==cur)
            newHead=newHead->next;
        delete cur;
        cur=nullptr;

        newHead=revers_list(newHead);
        return newHead;
    }
};