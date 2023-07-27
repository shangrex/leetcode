class node {
    public:
        int key;
        int value;
        node *prev;
        node *next;
    node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    };
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, node*>mp;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        // two dummy node, not certain meaning

        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        // check if in the LRU
        // if yes then return the value, and put the node in front of the head
        // if no then return -1
        if(mp.find(key) != mp.end()){
            node * curnode = mp[key];
            remove(curnode);
            insert(curnode);
            return curnode->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // check if in the LRU
        if(mp.find(key) != mp.end()){
            // if yes
            node* curnode = mp[key];
            remove(curnode);
            curnode->value = value;
            insert(curnode);
        }
        else {
            node *curnode = new node(key, value);
            if(mp.size() < this->capacity){
                insert(curnode);
            }
            else {
                insert(curnode);
                remove(tail->prev);
            }
        }
        // if yes then touch the node and put the node in the head of the LRU and update the value
        // if no then add new node in front of the head, and if the list over the capacity delete the last node 
    }
    
    void insert(node* curnode){
        curnode->next = head->next;
        head->next->prev = curnode;
        head->next = curnode;
        curnode->prev = head;
        
        mp[curnode->key] = curnode;
    }
    
    void remove(node *curnode){
        mp.erase(curnode->key);
        curnode->prev->next = curnode->next;
        curnode->next->prev = curnode->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */