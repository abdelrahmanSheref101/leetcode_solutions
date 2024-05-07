
// the design for this ds is as following:
    // that the lru will always be the tail 
    // so insert will insert to the right of the head 
    // both insert and remove will take a node as an argument so O(1) complexity , i.e. no need to iterate over the list
    // at put : insert , remove lru(tail) , earse lru from that hash map
    // at get : remove the key's node, insert the key's node , return the key's data

class LRUCache {
    //link , insert , remove are utilities
    struct listNode{
        int  K{};
        int  data{};
        listNode * next{};
        listNode * prev{};
        listNode(int val,int k):data(val),K(k),next(NULL),prev(NULL){}
    };
    void link(listNode * first,listNode * second){
        if(first)
            first->next=second;
        if(second)
            second->prev=first;
    }

    int cap,
        added_elms=0;
    unordered_map<int,listNode*> mp;

    listNode * head=new listNode(0,0);
    listNode * tail=new listNode(0,0);
    // head and tail are linked in the constructor  

    //insert to right of the head
    void insert(listNode * node){
        listNode * next=head->next;
        link(head,node);
        link(node,next);
    }

    //  it doesn't actually free the allocated memory it just rewire the list
    void remove(listNode * node){
        link(node->prev,node->next);
    }


public:
    LRUCache(int capacity):cap(capacity) {
        link(head,tail);
    }
    
    int get(int key) {
        //to get you just retrive the value from the node from the hash map
        //then remove and reinsert it
        if(mp.count(key)){
            int val=mp[key]->data;
            remove(mp[key]);
            insert(mp[key]);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
       //if the key is already used , remove override the value , then insert again
        if(mp.count(key)){
            remove(mp[key]);
            mp[key]->data=value;
            insert(mp[key]);
        }
        //new key
        else {
            int n=mp.size();
            if(n==cap)
            {
                listNode *lru=tail->prev;
                remove(lru);
                mp.erase(lru->K);
                delete lru;

            }
            listNode * itm=new listNode(value,key);
            mp[itm->K]=itm;
            insert(itm);

        }
    }


};