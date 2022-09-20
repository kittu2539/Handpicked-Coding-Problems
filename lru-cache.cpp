// link :- https://leetcode.com/problems/lru-cache/
class node{
public:
    int key, value;
    struct node *next, *prev;
    node(int key,int value){
        this->key=key;
        this->value=value;
        next=NULL,prev=NULL;
    }
};
class LRUCache {
private:
    int sz,cursz;
    node *head,*tail;
    map<int,node *>address;
public:
    LRUCache(int capacity) {
        sz=capacity;
        cursz=0;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void remove(node *tm,bool choice){
        node * tml = tm->prev,*tmr = tm->next;
        tml->next=tmr;
        tmr->prev=tml;
        if(choice)
            delete(tm);
    }
    void insert_front(node* tm){
        node *tmr=head->next,*tml=head;
        tml->next=tm;tm->prev=tml;
        tm->next=tmr;tmr->prev=tm;
    }
    int get(int key) {
        // return -2;
        if(address.find(key)==address.end()){
            return -1;
        }
        node *tm = address[key];
        remove(tm,0);
        insert_front(tm);
        return tm->value;
    }
    void put(int key, int val) {
        // return;
        if(address.find(key)==address.end()){
            if(cursz==sz){
                address.erase(tail->prev->key);
                remove(tail->prev,1);
                cursz--;
            }
            cursz++;
            node *tm = new node(key,val);
            insert_front(tm);
            address[key]=tm;
        }else {
            node *tm = address[key];
            remove(tm,0);
            tm->value=val;
            insert_front(tm);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
