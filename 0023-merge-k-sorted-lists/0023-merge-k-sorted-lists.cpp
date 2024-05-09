/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
    ListNode * mergeTwoLists(ListNode * head1,ListNode * head2){
        if(!head1&&!head2)
            return NULL;
        if(!head2)
            return head1;
        if(!head1)
            return head2;

        ListNode * newHead=NULL;

        if(head1->val>head2->val)
        {
            newHead=head2;
            head2=head2->next;
        }
        else
        {
            newHead=head1;
            head1=head1->next;
        }
        ListNode * cur=newHead;

        while (head1&&head2)
        {
            if(head1->val>head2->val)
            {
                cur->next=head2;
                head2=head2->next;
            }
            else
            {
                cur->next=head1;
                head1=head1->next;
            }
            cur=cur->next;
        }

        if(!head1)
            cur->next=head2;
        else
            cur->next=head1;



        return newHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(!n)
            return NULL;

        while(n>1) 
        {
            for(int i=0;i<n/2;i++){
                //merge first with end
                lists[i]=mergeTwoLists(lists[i],lists[n-i-1]);
            }
            n=(n+1)/2;
        }

        return lists[0];
        
    }
};