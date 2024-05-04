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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*newHead=new ListNode();
        bool carry=0;
        ListNode *cur=newHead;
        while (l1!=0||l2!=0)
        {
            int sum=0;
            if(l1)
                sum+=l1->val;
            if(l2)
                sum+=l2->val;
            if(carry) 
                sum++,carry=0;

            if(sum>=10)
            {
                carry=1;
                sum=sum%10;
            }

            cur->val=sum;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            if(l1||l2)
            {
                cur->next=new ListNode();
                cur=cur->next;
            }
        }
        if(carry)
            cur->next=new ListNode(1);
        
        return newHead;
    }
};
