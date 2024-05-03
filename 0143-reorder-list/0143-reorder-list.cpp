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
class Solution{
    private:
        ListNode* getMid(ListNode *head){
            if(!head||!head->next)
                return head;

            ListNode * slowptr=head;
            ListNode * fastptr=head->next;
            while (fastptr&&fastptr->next)
            {
                slowptr=slowptr->next;
                fastptr=fastptr->next->next;
            }
            return slowptr;
        }
        ListNode* reversList(ListNode * node){
                if(!node||!node->next)
                    return node;
                ListNode *cur=node;
                ListNode *prev=nullptr;
                while(cur)
                {
                    ListNode *tmp=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=tmp;
                }
                return prev;
        }

    public:
    void reorderList(ListNode* head) {
        ListNode *midNode=getMid(head);
        
        ListNode *rear=reversList(midNode->next);
        ListNode *front=head;
        while(front&&rear){
            ListNode *nfront=front->next;
            ListNode *nrear=rear->next;

            front->next=rear; 
            rear->next=nfront;

            front=nfront;
            rear=nrear;
        }
        front->next=nullptr;

    }
};