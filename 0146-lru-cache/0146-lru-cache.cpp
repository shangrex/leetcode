class node {
    public:
    node *post;
    node *prev;
    int capacity;
    int key, value;
    node(int key, int value){
        this->key = key;
        this->value = value;
        this->post = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
public:
    // store all key and the node address
    unordered_map<int, node*>mp;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);
    int capacity;
    
    
    void remove(node* r_node){
        node *prev = r_node->prev;
        node *next = r_node->post;
        prev->post = next;
        next->prev = prev;
    }
    
    
    // add the node in the head of the list
    void insert(node *i_node){
        node *next = head->post;
        next->prev = i_node;
        head->post = i_node;
        i_node->post = next;
        i_node->prev = head;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->post = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            // node*cur = head;
            // while(cur){
            //     cout << cur->value << endl;
            //     cur = cur->post;
            // }
            return mp[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
          
        if(mp.find(key) != mp.end()){
            // key already exist
            cout << "touch " << key << endl;
            remove(mp[key]);
            insert(mp[key]);
            mp[key]->value = value;
        }
        else {
            // cout << this->capacity << endl;
            // cout << mp.size();
            if(this->capacity == mp.size()){
                cout <<"remove value : " << tail->prev->value << endl;
                node *element_tail = tail->prev;
                remove(element_tail);
                mp.erase(element_tail->key);
                
                node *new_node = new node(key, value);
                insert(new_node);
                mp[key] = new_node;
                
            }
            else {
                cout << "input" << key << " " << value << endl;
                node *new_node = new node(key,value);
                insert(new_node);
                mp[key] = new_node;
                //cout << "size" << mp.size() << endl;
            }
            //  node*cur = head;
            // while(cur){
            //     cout << cur->value << endl;
            //     cur = cur->post;
            // }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */