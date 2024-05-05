/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //instead of trying to find the whole list we can just delete the next node to "node" 
        //such that prev = node  , cur=node->next
        //then copy the value of cur to prev
        ListNode*prev=node;
        ListNode*cur=node->next;
        int tmp= cur->val;
        prev->next=cur->next;
        delete cur;
        prev->val=tmp;
    }
};
