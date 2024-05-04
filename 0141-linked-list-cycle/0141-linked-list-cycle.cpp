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
    bool hasCycle(ListNode *head) {
            unordered_set<ListNode *>st; 
            for(ListNode*cur=head;cur;cur=cur->next){
                if(!st.insert(cur).second)
                    return true;
            }
            return false;
    }
};