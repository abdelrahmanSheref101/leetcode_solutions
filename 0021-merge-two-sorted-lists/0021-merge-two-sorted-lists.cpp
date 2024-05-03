class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1&&!list2)
            return nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode *dummyHead=new ListNode();
        ListNode *cur=dummyHead;
        while (list1&&list2)
        {
            if(list1->val>list2->val)
            {
                cur->next=list2; 
                list2=list2->next;
            }
            else
            {
                cur->next=list1; 
                list1=list1->next;
            }
            cur=cur->next;
        }
        if(!list1)
            cur->next=list2;
        else
            cur->next=list1;

        return dummyHead->next;
    }
};