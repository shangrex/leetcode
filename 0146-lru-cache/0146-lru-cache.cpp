// craete node
class node {
    public:
    
    node* prev;
    node* post;
    int key;
    int value;
    node (int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->post = NULL;
    }
};


class LRUCache {
public:
    // store all key and the node address
    unordered_map<int, node*>mp;
    int capacity;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);
    
    void remove(node* r_node){
        node *prev = r_node->prev;
        node *post = r_node->post;
        
        post->prev = r_node->prev;
        prev->post = r_node->post;
    }
    
    
    // add the node in the head of the list
    void insert(node *i_node){
        
        i_node->post = head->post;
        head->post->prev = i_node;
        i_node->prev = head;
        head->post = i_node;
        
    }
    
    LRUCache(int capacity) {
        
        this->capacity = capacity;
        
        head->post = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->post = NULL;
    }
    
    int get(int key) {
        // check if in map
        if(mp.find(key) != mp.end()){
            // if yes return and remove the node then add the node on top of the list
            node *tmp = mp[key];
            remove(tmp);
            insert(tmp);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        // check the node if in map if yes then remove the node and add the node in the head
        if(mp.find(key) != mp.end()){
            mp[key]->value = value;
            remove(mp[key]);
            insert(mp[key]);
        }
        else {
            if(mp.size() >= this->capacity){
                mp.erase(tail->prev->key);
                remove(tail->prev);
            }
            node *new_node = new node(key, value);
            mp[key] = new_node;
            insert(new_node);
        }
        
        // if no
        
        // delete the tail node and put the new node in the head of node 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */