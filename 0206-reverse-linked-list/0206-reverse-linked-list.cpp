class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            if(head==nullptr||head->next==nullptr)
                return head;
            ListNode *cur=head;
            ListNode *prev=nullptr;
            while(cur) 
            {

                ListNode *tmp;
                    tmp=cur->next;

                cur->next=prev;
                prev=cur;
                cur=tmp;
            }
            return prev;
        }
    
};