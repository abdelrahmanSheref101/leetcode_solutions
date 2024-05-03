/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        if(!head->next){
            Node * tmp=new Node(head->val);
            if(head->random==head)
                tmp->random=tmp;
            return tmp;
        }
        unordered_map<Node*,int>listNodes;
        vector<Node*>res;
        int i=0;
        for(Node*cur=head;cur;++i,cur=cur->next)
        {
            listNodes[cur]=i;   //this index each element so we search for it again we know its index 
                                //,we can find the coressbonding node in the vector

            // creates new nodes and link them
            res.push_back(new Node(cur->val));
            if(i)
                res[i-1]->next=res[i];
        }
        i=0;
        for(Node*cur=head;cur;i++,cur=cur->next)
        {
            if(cur->random){
                int idxOfRand=listNodes[cur->random];
                res[i]->random=res[idxOfRand];
            }
          
        }
        
        return res[0];
    }
};